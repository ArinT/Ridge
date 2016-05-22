__author__ = 'Arin'
import unittest
from Models.Map import Map
from Models.Units.GreaserUnit import GreaserUnit
from Models.Units.BruiserUnit import BruiserUnit
from Models.Units.SquabblerUnit import SquabblerUnit
from Models.Units.Constants import CONST
import pygame


class TestModel(unittest.TestCase):
    def setUp(self):
        pygame.init()

    def test_simple_move(self):
        m = Map(10, 10)
        m.generate_from_ascii("Models/Maps/10by10.txt")
        g = GreaserUnit(4, 4, m, CONST.jets)
        assert (g.move(5, 4))
        assert (g.x == 5 and g.y == 4)
        assert (m.unit_at(5, 4) is g)

    def test_a_star_issue(self):
        m = Map(32,18)
        m.generate_from_ascii("Models/Maps/32by18.txt")
        g = GreaserUnit(4,10,m,CONST.jets)
        g.move(0,10)
    def test_valid_moves(self):
        m = Map(32,18)
        m.generate_from_ascii("Models/Maps/32by18.txt")
        g = GreaserUnit(4,10,m,CONST.jets)
        g.valid_moves()

    def testMoveTooFar(self):
        m = Map(10, 10)
        m.generate_from_ascii("Models/Maps/10by10funnel.txt")
        g = GreaserUnit(8, 1, m, CONST.jets)
        assert (not g.move(1, 6))
        assert (g.move(6, 3))

    def testMoveThroughFriendly(self):
        m = Map(10, 10)
        m.generate_from_ascii("Models/Maps/10by10funnel.txt")
        g = GreaserUnit(4, 3, m, CONST.jets)
        b = BruiserUnit(4, 4, m, CONST.jets) ##blocked by teammate
        assert (g.move(4, 6))
        assert (g.x == 4 and g.y == 6)
        assert (m.unit_at(4, 6) is g)

    def testMoveOnFriendly(self):
        m = Map(10, 10)
        m.generate_from_ascii("Models/Maps/10by10funnel.txt")
        g = GreaserUnit(8, 3, m, CONST.jets)
        b = BruiserUnit(8, 4, m, CONST.jets) ##blocked by teammate
        assert (not g.move(8, 4))
    
    def test_move_on_friendly_far(self):
        m = Map(3, 10)
        m.generate_from_ascii("Models/Maps/corridor.txt")
        g = GreaserUnit(0, 0, m, CONST.jets)
        g1 = GreaserUnit(0, 5, m, CONST.jets)
        assert (not g.move(0, 5))
        assert (g.move(0, 4))

    def testMoveThroughEnemy(self):
        m = Map(10, 10)
        m.generate_from_ascii("Models/Maps/10by10funnel.txt")
        g = GreaserUnit(8, 3, m, CONST.jets)
        b = BruiserUnit(8, 4, m, CONST.sharks) ##blocked by teammate
        assert (not g.move(8, 5))

    def testMoveAroundEnemy(self):
        m = Map(3, 10)
        m.generate_from_ascii("Models/Maps/corridor.txt")
        g = GreaserUnit(1, 2, m, CONST.jets)
        b1 = BruiserUnit(2, 3, m, CONST.sharks) ##blocked by teammate
        b2 = BruiserUnit(1, 3, m, CONST.sharks) ##blocked by teammate
        assert (g.move(1, 4))

    def testAttackSimple(self):
        m = Map(10, 10)
        m.generate_from_ascii("Models/Maps/10by10.txt")
        g = GreaserUnit(8, 3, m, CONST.jets)
        b = BruiserUnit(8, 4, m, CONST.sharks) ##blocked by teammate
        s = b.hp
        assert (g.attack(8, 4))
        assert (b.hp < s)

    def testAttackComplex(self):
        m = Map(10, 10)
        m.generate_from_ascii("Models/Maps/10by10.txt")
        s = SquabblerUnit(8, 3, m, CONST.jets)
        b = BruiserUnit(8, 5, m, CONST.sharks) ##blocked by teammate
        h = b.hp
        assert (s.attack(8, 5))
        assert (b.hp < h)

    def testInvalidAttack(self):
        m = Map(10, 10)
        m.generate_from_ascii("Models/Maps/10by10.txt")
        s = SquabblerUnit(8, 4, m, CONST.jets)
        b = BruiserUnit(8, 5, m, CONST.jets) ##blocked by teammate
        assert (not s.attack(7, 4))
        assert (not s.attack(8, 5))


if __name__ == '__main__':
    unittest.main()
