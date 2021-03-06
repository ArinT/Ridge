__author__ = 'Arin'
import unittest

from models.units.bruiser_unit import BruiserUnit
from models.units.greaser_unit import GreaserUnit
from models.units.squabbler_unit import SquabblerUnit
from models.map import Map
from models.units.constants import CONST
import pygame

class TestUnit(unittest.TestCase):
    def setUp(self):
        pygame.init()

    def test_bruiser(self):
        n = Map(6, 4)
        n.generate_from_ascii("models/maps/6by4.txt")
        b = BruiserUnit(0, 0, n, CONST.jets)
        assert (b.max_hp >= CONST.bruiser_min_hp and b.max_hp <= CONST.bruiser_max_hp)
        assert (b.map == n)
        assert (b.finesse >= CONST.bruiser_min_finesse and b.finesse <= CONST.bruiser_max_finesse)
        assert (b.x == 0 & b.y == 0)

    def test_greaser(self):
        n = Map(6, 4)
        n.generate_from_ascii("models/maps/6by4.txt")
        g = GreaserUnit(2, 2, n, CONST.jets)
        assert (g.max_hp >= CONST.greaser_min_hp
                            & g.max_hp <= CONST.greaser_max_hp)
        assert (g.finesse >= CONST.greaser_min_finesse
                             & g.finesse <= CONST.greaser_max_finesse)
        assert (g.x == 2 & g.y == 2)
        assert (g.team == CONST.jets)

    def test_squabbler(self):
        n = Map(6, 4)
        n.generate_from_ascii("models/maps/6by4.txt")
        s = SquabblerUnit(2, 2, n, CONST.jets)
        assert (s.max_hp >= CONST.squabbler_min_hp
                            & s.max_hp <= CONST.squabbler_max_hp)
        assert (s.finesse >= CONST.squabbler_min_finesse
                             & s.finesse <= CONST.squabbler_max_finesse)
        assert (s.x == 2 & s.y == 2)
        assert (s.team == CONST.jets)

    def test_unit_death(self):
        n = Map(6, 4)
        n.generate_from_ascii("models/maps/6by4.txt")
        s = SquabblerUnit(2, 2, n, CONST.jets)
        s.receive_damage(9)
        assert (n.unit_at(2, 2) is None)


if __name__ == '__main__':
    unittest.main()
