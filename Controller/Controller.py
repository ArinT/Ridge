__author__ = 'Arin'
from pygame.locals import *
import pygame,os
from Models.Units.Constants import CONST
def load_sound(name):
    class NoneSound:
        def play(self): pass
    if not pygame.mixer:
        return NoneSound()
    fullname = os.path.join(os.path.abspath(os.path.curdir), name)
    try:
        sound = pygame.mixer.Sound(fullname)
    except pygame.error, message:
        print 'Cannot load sound:', name
        raise SystemExit, message
    return sound

class Controller(object):
    def __init__(self, view, map):
        self.map = map
        self.view = view
        self.unit = None
        self.cursor = self.view.cursor
        self.conf = load_sound(CONST.conf)
        self.conf.set_volume(.5)
        self.cncl = load_sound(CONST.cncl)
        self.last_loc = [0,0]
        self.phase = CONST.select
        pygame.key.set_repeat(250,50)

    def notify(self, event):
        if event.type == KEYDOWN:
            self.handle_key(event.key)


    def handle_key(self, key):
        if  key == K_ESCAPE:
                raise SystemExit, "User quit" #Must be a neater way?
        elif key == K_DOWN:
            self.move_cursor(self.cursor.x, self.cursor.y+1)
        elif key == K_UP:
            self.move_cursor(self.cursor.x, self.cursor.y-1)
        elif key == K_RIGHT:
            self.move_cursor(self.cursor.x+1, self.cursor.y)
        elif key == K_LEFT:
            self.move_cursor(self.cursor.x-1, self.cursor.y)
        elif key == K_z:
            self.confirm()
        elif key == K_x:
            self.cancel()
        elif key == K_c:
            self.wait()
        elif key == K_v:
            self.try_special()
        elif key == K_BACKSPACE:
            self.end_turn()
        elif key == K_f:
            self.view.flag = self.view.flag ^ FULLSCREEN
            pygame.display.set_mode((1920, 1080), self.view.flag)
    def end_turn(self):
        if self.phase != CONST.select:
            return

        self.map.switch_turns()
    def move_cursor(self,x,y):
        if not self.view.menu.is_open:
            self.view.move_cursor(x,y)
    def wait(self):
        if self.phase== CONST.menu:
            self.phase=CONST.select
            self.view.hide_menu()
            self.unit.ready= False
            self.unit = None


    def undo_move(self):
        self.unit.move(self.last_loc[0], self.last_loc[1])
        self.last_loc = [0, 0]

    def cancel_attack(self):
        self.phase = CONST.menu
        self.view.show_menu()
        self.map.unmark()
        self.cncl.play()
    def cancel(self):
        if self.phase == CONST.menu:
            self.undo_move()
        elif self.phase == CONST.attack or self.phase == CONST.special:
            self.cancel_attack()
            return
        self.phase=CONST.select
        self.view.hide_menu()
        self.unit = None
        self.map.unmark()
        self.cncl.play()
    def confirm(self):
        if self.phase==CONST.select:
            self.select()
        elif self.phase == CONST.move:
            self.move()
        elif self.phase == CONST.menu:
            self.aim_attack()
        elif self.phase == CONST.attack:
            self.attack()
        elif self.phase == CONST.special:
            self.execute_special()
    def aim_attack(self):
        any_valid = self.unit.valid_attacks()
        if any_valid:
            self.phase=CONST.attack
            self.view.hide_menu()
            self.conf.play()
        else:
            self.cncl.play()
    def select(self):
        x = self.cursor.x
        y = self.cursor.y
        self.unit = self.map.unit_at(x,y)
        if self.unit is not  None and self.unit.is_ready():
            self.unit.valid_moves()
            self.phase = CONST.move
            self.conf.play()

    def attack_contacted(self):
        self.unit.at_sfx.play()
        self.phase = CONST.select
        self.view.info_pane.set_unit_info(self.cursor.x,self.cursor.y)
        self.unit.ready = False
        self.unit = None
        self.map.unmark()

    def attack(self):
        success = self.unit.attack(self.cursor.x,self.cursor.y)
        if success:
            self.attack_contacted()
        else:
            self.cncl.play()
    def try_special(self):
        if self.phase == CONST.menu:
            self.aim_special()
    def aim_special(self):
        any_valid = self.unit.valid_attacks()
        if any_valid:
            self.phase=CONST.special
            self.view.hide_menu()
        else:
            self.cncl.play()
    def execute_special(self):
        success = self.unit.special_attack(self.cursor.x, self.cursor.y)
        if success:
            self.attack_contacted()
        else:
            self.cncl.play()
    def make_move(self, previous_pos):
        self.view.show_menu()
        self.unit.mv_sfx.play()
        self.map.unmark()
        self.phase = CONST.menu
        self.last_loc = previous_pos

    def move(self):
            x = self.cursor.x
            y = self.cursor.y
            if not self.your_turn():
                self.cncl.play()
                return
            previous_pos = [self.unit.x,self.unit.y]
            success = self.unit.move(x,y)
            if success:
                self.make_move(previous_pos)
            else:
                self.cncl.play()
    def your_turn(self):
        team = self.unit.team
        return (self.map.sharks_turn and team == CONST.sharks) or\
               (not self.map.sharks_turn and team == CONST.jets)

