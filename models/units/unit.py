__author__ = 'Arin'
import abc
import pygame,os
from models.units.constants import CONST

class Unit(object):
    """Unit abtract class. Every unit has the same same stat fields."""
    __metaclass__ = abc.ABCMeta

    def __init__(self, x, y, map, team, max_hp, strength,
                 finesse, wit, style, movement, image_path,sfx):
        """Constructor is called by subclasses"""
        self.movement = movement
        self.max_hp = max_hp
        self.strength = strength
        self.finesse = finesse
        self.wit = wit
        self.style = style
        self.x = x
        self.y = y
        self.hp = self.max_hp
        self.ready = True
        self.demoralize = False
        self.map = map
        self.team = team
        self.is_alive = True
        self.image_path = image_path
        self.map.add_unit(self)
        self.at_sfx=load_sound(sfx)
        self.mv_sfx=load_sound(CONST.move_sfx)


    def move(self, x, y):
        """Makes calls to the maps a* function and adjusts a few unit fields"""
        path = self.get_path(x, y)
        if (len(path) == 0):
            return False
        self.map.move_unit(path)
        self.x = x
        self.y = y
        return True
    def no_move(self,x,y):
        return self.x==x and self.y==y
    def get_path(self, dest_x, dest_y):
        """Makes the a* call and returns the path. """
        #Short circuit to prevent running the whole map on a*
        if not self.map.can_go_to(dest_x,dest_y) and\
                not self.no_move(dest_x,dest_y):
            return []
        start = self.map.tile_matrix[self.x][self.y]
        end = self.map.tile_matrix[dest_x][dest_y]
        shortest_path = self.map.a_star(start, end, self.team)
        if len(shortest_path) - 1 > self.movement:
            return []
        return shortest_path

    def attack(self, attack_x, attack_y):
        """Checks if this unit can attack the tile and executes it if so"""
        if (self.can_attack(attack_x, attack_y)):
            attackee = self.map.unit_at(attack_x, attack_y)
            dmg = self.calculate_damage(attackee)
            attackee.receive_damage(dmg)
            return True
        return False

    @abc.abstractmethod
    def can_attack(self, attack_x, attack_y):
        """Checks if this unit can attack tile"""
        if self.map.out_of_bounds(attack_x,attack_y):
            return False
        unit = self.map.unit_at(attack_x, attack_y)
        if (unit is None or unit.team == self.team):
            return False
        return True

    @abc.abstractmethod
    def special_attack(self, attack_x, attack_y):
        """abstract method defined by subclasses"""
        pass

    @abc.abstractmethod
    def calculate_damage(self, unit):
        pass

    def is_ready(self):
        return self.ready and not self.demoralize
    def receive_damage(self, amount):
        """Does damage to unit health"""
        self.hp -= amount
        if self.hp <= 0:
            self.is_alive = False
            self.map.delete_unit(self)
    def valid_attacks(self):
        ret = False
        for i in range(-2,3):
            for j in range (-2,3):
                if self.can_attack(self.x+i,self.y+j):
                    ret = True
                    self.map.tile_matrix[self.x+i][self.y+j].at_marked = True
        return ret
    def valid_moves(self):
        for row in self.map.tile_matrix:
            for tile in row:
                if m_dist(self.x, self.y, tile.x, tile.y)<=self.movement:
                    if len(self.get_path(tile.x, tile.y)) != 0:
                        tile.marked=True



def load_sound(name):
    class NoneSound:
        def play(self): pass
    if not pygame.mixer:
        return NoneSound()
    fullname = os.path.join(os.path.abspath(os.path.curdir), name)
    try:
        sound = pygame.mixer.Sound(fullname)
    except pygame.error and MemoryError, message:
        print 'Cannot load sound:', name
        sound= NoneSound
    return sound
def m_dist(x, y, a, b):
    """manhattan distance"""
    return abs(x - a) + abs(y - b)
