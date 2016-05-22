__author__ = 'Arin'
import unittest
from Models.Map import Map
from Models.Tiles.SceneryTile import SceneryTile
from Models.Tiles.GrassTile import GrassTile
from Models.Tiles.WallTile import WallTile
from Models.Tiles.ConcreteTile import ConcreteTile
from Models.Tiles.RoadTile import RoadTile
from Models.Units.GreaserUnit import GreaserUnit
from Models.Units.BruiserUnit import BruiserUnit
from Models.Units.SquabblerUnit import SquabblerUnit
from Models.Units.Constants import CONST
from Models.Map import Node
import pygame


class TestGenerateMap(unittest.TestCase):
    def setUp(self):
        pygame.init()

    def test_square_map(self):
        m = Map(10, 10)
        m.generate_from_ascii("Models/Maps/10by10.txt")
        assert (isinstance(m.tile_matrix[0][0], WallTile))
        assert (isinstance(m.tile_matrix[0][9], GrassTile))
        assert (isinstance(m.tile_matrix[4][1], ConcreteTile))
        assert (isinstance(m.tile_matrix[1][9], SceneryTile))
        assert (isinstance(m.tile_matrix[2][9], RoadTile))
        assert (isinstance(m.tile_matrix[3][9], GrassTile))
        assert (isinstance(m.tile_matrix[4][9], ConcreteTile))
        assert (isinstance(m.tile_matrix[9][9], WallTile))

    def test_rect_map(self):
        n = Map(6, 4)
        n.generate_from_ascii("Models/Maps/6by4.txt")
        assert (isinstance(n.tile_matrix[0][0], WallTile))
        assert (isinstance(n.tile_matrix[5][0], WallTile))
        assert (isinstance(n.tile_matrix[4][2], RoadTile))
        assert (isinstance(n.tile_matrix[0][3], GrassTile))
        assert (isinstance(n.tile_matrix[3][1], ConcreteTile))
        assert (isinstance(n.tile_matrix[5][3], SceneryTile))

class TestMapUtilities(unittest.TestCase):
    def test_add_remove_unit(self):
        m = Map(10, 10)
        m.generate_from_ascii("Models/Maps/10by10.txt")
        g = GreaserUnit(2, 2, m, CONST.jets)
        assert (m.tile_matrix[2][2].is_occupied)
        assert (not m.tile_matrix[3][3].is_occupied)
        b = BruiserUnit(3, 3, m, CONST.jets)
        assert (m.tile_matrix[3][3].is_occupied)
        s = SquabblerUnit(4, 4, m, CONST.jets)
        assert (m.tile_matrix[4][4].is_occupied)
        m.delete_unit(g)
        assert (not m.tile_matrix[2][2].is_occupied)
        m.delete_unit(b)
        assert (not m.tile_matrix[3][3].is_occupied)
        m.delete_unit(s)
        assert (not m.tile_matrix[4][4].is_occupied)

    def test_piece_at(self):
        m = Map(10, 10)
        m.generate_from_ascii("Models/Maps/10by10.txt")
        g = GreaserUnit(2, 2, m, CONST.jets)
        assert (m.unit_at(2, 2) == g)
        m.delete_unit(g)
        assert (m.unit_at(2, 2) == None)

    def test_is_enemy_occupied(self):
        m = Map(10, 10)
        m.generate_from_ascii("Models/Maps/10by10.txt")
        g = GreaserUnit(2, 2, m, CONST.jets)
        assert (m.is_enemy_occupied(2, 2, CONST.sharks))
        assert (not m.is_enemy_occupied(2, 2, CONST.jets))

    def test_can_go_inaccessible(self):
        m = Map(10, 10)
        m.generate_from_ascii("Models/Maps/10by10.txt")
        assert (not m.can_go_through(0, 0, CONST.jets))
        assert ( m.can_go_through(4, 5, CONST.jets))

    def test_can_go_out_of_bounds(self):
        m = Map(10, 10)
        m.generate_from_ascii("Models/Maps/10by10.txt")
        m.can_go_through(-1, 0, CONST.jets)
        m.can_go_through(8, 0, CONST.jets)
        m.can_go_through(0, 8, CONST.jets)
        m.can_go_through(0, -1, CONST.jets)

    def test_can_go_through_unit(self):
        m = Map(10, 10)
        m.generate_from_ascii("Models/Maps/10by10.txt")
        g = GreaserUnit(4, 5, m, CONST.jets)
        assert (m.can_go_through(4, 5, CONST.jets))
        assert (not m.can_go_through(4, 5, CONST.sharks))

    def test_neighboring_tiles_all_good(self):
        m = Map(10, 10)
        m.generate_from_ascii("Models/Maps/10by10.txt")
        x = 4
        y = 5
        n = Node(m.tile_matrix[x][y], 0, None)
        neighbors = m.neighboring_tiles(n, CONST.jets)
        up = m.tile_matrix[x][y-1]
        down = m.tile_matrix[x][y+1]
        right = m.tile_matrix[x+1][y]
        left = m.tile_matrix[x-1][y]
        assert (len(neighbors) == 4)
        assert (up in neighbors)
        assert (down in neighbors)
        assert (right in neighbors)
        assert (left in neighbors)

    def test_neighboring_tiles_some_good(self):
        m = Map(10, 10)
        m.generate_from_ascii("Models/Maps/10by10.txt")
        n = Node(m.tile_matrix[4][1], 0, None)
        neighbors = m.neighboring_tiles(n, CONST.jets)
        up = m.tile_matrix[4][0]
        down = m.tile_matrix[4][2]
        right = m.tile_matrix[5][1]
        left = m.tile_matrix[3][1]
        assert (len(neighbors) == 2)
        assert (up not in neighbors)
        assert (down in neighbors)
        assert (right in neighbors)
        assert (left not in neighbors)

    def test_neighboring_tiles_all_bad(self):
        m = Map(10, 10)
        m.generate_from_ascii("Models/Maps/10by10.txt")
        n = Node(m.tile_matrix[0][0], 0, None)
        neighbors_0_0 = m.neighboring_tiles(n, CONST.jets)
        assert (len(neighbors_0_0) == 0)

class TestAStar(unittest.TestCase):
    def setUp(self):
        pygame.init()
    def test_a_star_zero_length(self):
        m = Map(10, 10)
        m.generate_from_ascii("Models/Maps/10by10.txt")
        start = m.tile_matrix[1][1]
        end = m.tile_matrix[1][1]
        path = m.a_star(start, end, CONST.jets)
        assert (len(path) == 1)
        assert (path[0] == start)
        assert (path[len(path) - 1] == end)

    def test_a_star_short_unobstructed(self):
        m = Map(10, 10)
        m.generate_from_ascii("Models/Maps/10by10.txt")
        start = m.tile_matrix[5][5]
        end = m.tile_matrix[4][4]
        path = m.a_star(start, end, CONST.jets)
        assert (len(path) == 3)
        for tile in path:
            assert (m.can_go_through(tile.x, tile.y, CONST.jets))
        assert (path[0] == start)
        assert (path[len(path) - 1] == end)

    def test_a_star_long_unobstructed(self):
        m = Map(10, 10)
        m.generate_from_ascii("Models/Maps/10by10test.txt")
        start = m.tile_matrix[1][1]
        end = m.tile_matrix[5][8]
        path = m.a_star(start, end, CONST.jets)
        for tile in path:
            assert (m.can_go_through(tile.x, tile.y, CONST.jets))
        assert (path[0] == start)
        assert (path[len(path) - 1] == end)

    def test_a_star_short_obstacles(self):
        m = Map(10, 10)
        m.generate_from_ascii("Models/Maps/10by10funnel.txt")
        start = m.tile_matrix[4][2]
        end = m.tile_matrix[7][2]
        path = m.a_star(start, end, CONST.jets)
        for tile in path:
            assert (m.can_go_through(tile.x, tile.y, CONST.jets))
        assert (path[0] == start)
        assert (path[len(path) - 1] == end)

    def test_a_star_long_obstacles(self):
        m = Map(10, 10)
        m.generate_from_ascii("Models/Maps/10by10funnel.txt")
        start = m.tile_matrix[8][1]
        end = m.tile_matrix[1][6]
        path = m.a_star(start, end, CONST.jets)
        for tile in path:
            assert (m.can_go_through(tile.x, tile.y, CONST.jets))
        assert (path[0] == start)
        assert (path[len(path) - 1] == end)

    def test_a_star_blocked_by_environment(self):
        m = Map(10, 10)
        m.generate_from_ascii("Models/Maps/10by10divided.txt")
        start = m.tile_matrix[1][1]
        end = m.tile_matrix[1][7]
        path = m.a_star(start, end, CONST.jets)
        assert (len(path) == 0)

    def test_a_star_long_blocked_by_enemy(self):
        m = Map(10, 10)
        m.generate_from_ascii("Models/Maps/10by10funnel.txt")
        start = m.tile_matrix[4][1]
        end = m.tile_matrix[4][7]
        g = GreaserUnit(4, 4, m, CONST.sharks) #shark blocking the path
        path = m.a_star(start, end, CONST.jets)
        assert (len(path) == 0)

    def test_a_star_long_blocked_by_friendly(self):
        m = Map(10, 10)
        m.generate_from_ascii("Models/Maps/10by10funnel.txt")
        start = m.tile_matrix[4][1]
        end = m.tile_matrix[4][7]
        g = GreaserUnit(4, 4, m, CONST.jets)
        path = m.a_star(start, end, CONST.jets)
        for tile in path:
            assert (m.can_go_through(tile.x, tile.y, CONST.jets))
        assert (path[0] == start)
        assert (path[len(path) - 1] == end)

    def test_rout(self):
        m = Map(10, 10)
        m.generate_from_ascii("Models/Maps/10by10funnel.txt")
        g = GreaserUnit(8, 4, m, CONST.jets)
        assert (not m.jets_routed())
        assert (m.sharks_routed())


if __name__ == '__main__':
    unittest.main()
