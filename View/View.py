__author__ = 'Arin'
import pygame
from TileSprite import TileSprite
from UnitSprite import UnitSprite
from CursorSprite import CursorSprite
from MenuSprite import MenuSprite
from InfoPane import InfoPane
from Models.Units.Constants import CONST
import time
import math
import os

class View(object):
    def __init__(self, map):
        """Where the view is kept. Has knowledge of the model and draws it upon
        a layered pane. """
        pygame.init()
        self.clock = pygame.time.Clock()
        self.map = map
        self.set_up_screen()
        self.layered_pane = pygame.sprite.LayeredUpdates()
        self.set_up_background()
        self.set_up_cursor()
        self.set_up_tile_sprites()
        self.set_up_unit_sprites()
        self.set_up_menu()
        self.set_up_info_pane()
        self.set_up_turn_banner()
        pygame.display.flip()

    def set_up_screen(self):
        self.flag = pygame.FULLSCREEN
        self.screen = pygame.display.set_mode((1920, 1080), self.flag)
        pygame.display.set_caption("West Side Story: THE GAME")
    def set_up_turn_banner(self):
        self.banner = pygame.Surface((1800, 360))
        self.banner.fill((255,0,0)if not self.map.sharks_turn else (0,0,255))
        self.banner.set_alpha(255)
        self.font =pygame.font.Font(None,256)



    def set_up_background(self):
        self.background = pygame.Surface(self.screen.get_size())
        self.background = self.background.convert()
        self.background.fill((0, 0, 0))
        self.screen.blit(self.background, (0, 0))

    def move_cursor(self,x,y):
        if x<0 or x>=self.map.columns or y<0 or y>=self.map.rows:
            return
        self.cursor.x=x
        self.cursor.y=y
    def set_up_cursor(self):
        self.cursor = CursorSprite()
        self.layered_pane.add(self.cursor, layer = 3)
    def set_up_tile_sprites(self):
        for row in self.map.tile_matrix:
            for tile in row:
                self.layered_pane.add(TileSprite(tile), layer=1)

    def set_up_unit_sprites(self):
        for unit in self.map.unit_list:
            self.layered_pane.add(UnitSprite(unit), layer=2)
    def set_up_menu(self):
        self.menu = MenuSprite(self.cursor,self.map.columns, self.map.rows)
    def set_up_info_pane(self):
        self.info_pane = InfoPane(self.cursor, self.map, self.screen)

    def draw_info_pane(self):
        self.info_pane.update()

    def draw_sprites(self):
        self.layered_pane.update()
        self.layered_pane.draw(self.screen)

    def draw_banner(self):
        self.fade_banner()
        self.banner.fill((255,0,0)if not self.map.sharks_turn else (0,0,255))
        self.scribble("SHARKS TURN" if self.map.sharks_turn else "JETS TURN")
        self.screen.blit(self.banner, (60, 360))
    def scribble(self, name):
        name_text = self.font.render(name,1,(10,10,10))
        name_textpos = name_text.get_rect()
        name_textpos.centerx = self.banner.get_rect().centerx
        name_textpos.centery = self.banner.get_rect().centery
        self.banner.blit(name_text,name_textpos)
    def fade_banner(self):
        then = self.map.turn_start
        now = time.time()
        dif = now-then
        if dif> 2:
            self.banner.set_alpha(0)
        else:
            self.banner.set_alpha(math.sin(dif/2*3.14)*255)

    def update_view(self):
        """Redraw function. Also calls redraw function of every sprite"""
        self.screen.blit(self.background, (0, 0))
        self.draw_sprites()
        self.draw_info_pane()
        self.draw_banner()
        pygame.display.flip()
    def show_menu(self):
        self.layered_pane.add(self.menu,layer = 4)
        self.menu.is_open = True
    def hide_menu(self):
        self.layered_pane.remove(self.menu)
        self.menu.is_open = False


def load_sprite(name):
    """Basic utility function"""
    try:
        image = pygame.image.load(name)
    except pygame.error, message:
        print 'Cannot load image at:', name
        raise SystemExit, message
    image = image.convert()
    return image, image.get_rect()



