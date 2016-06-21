__author__ = 'Arin'
import unittest

from models.units.bruiser_unit import BruiserUnit
from models.units.greaser_unit import GreaserUnit
from models.units.squabbler_unit import SquabblerUnit
from models.map import Map
from models.units.constants import CONST
import pygame

class TestSpecialAttack(unittest.TestCase):
    def setUp(self):
        pygame.init()

    def test_greaser_special(self):
        m = Map(10, 10)
        m.generate_from_ascii("models/maps/10by10.txt")
        s = SquabblerUnit(8, 3, m, CONST.jets)
        g = GreaserUnit(8, 4, m, CONST.sharks)
        b = BruiserUnit(8, 5, m, CONST.jets)
        bh = b.hp
        sh = s.hp
        assert (g.special_attack(8, 5))
        assert (bh > b.hp and sh > s.hp)

    def test_squabbler_special(self):
        m = Map(10, 10)
        m.generate_from_ascii("models/maps/10by10.txt")
        s = SquabblerUnit(8, 3, m, CONST.jets)
        g = GreaserUnit(8, 4, m, CONST.sharks)
        gw = g.wit
        s.special_attack(8, 4)
        assert (g.demoralize)

    def test_bruiser_special_shove(self):
        m = Map(10, 10)
        m.generate_from_ascii("models/maps/10by10.txt")
        g = GreaserUnit(8, 4, m, CONST.sharks)
        b = BruiserUnit(8, 5, m, CONST.jets)
        gh = g.hp
        assert (b.special_attack(8, 4))
        assert (gh > g.hp)
        assert (m.unit_at(8, 3) is g)

    def test_bruiser_special_collide(self):
        m = Map(10, 10)
        m.generate_from_ascii("models/maps/10by10.txt")
        s = GreaserUnit(8, 3, m, CONST.sharks)
        g = GreaserUnit(8, 4, m, CONST.sharks)
        b = BruiserUnit(8, 5, m, CONST.jets)
        assert (b.special_attack(8, 4))
        assert (m.unit_at(8, 3) is s)


if __name__ == '__main__':
    unittest.main()
