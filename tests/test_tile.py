__author__ = 'Arin'
import unittest
from models.tiles.scenery_tile import SceneryTile
from models.tiles.grass_tile import GrassTile
from models.tiles.wall_tile import WallTile
from models.tiles.concrete_tile import ConcreteTile
from models.tiles.road_tile import RoadTile


class TestTile(unittest.TestCase):
    def testTiles(self):
        c = SceneryTile(1, 1)
        m = WallTile(1, 1)
        r = RoadTile(1, 1)
        p = ConcreteTile(1, 1)
        f = GrassTile(1, 1)
        assert (0 == r.get_defense_value())
        assert (1 == p.get_defense_value())
        assert (2 == f.get_defense_value())
        assert ("X" == m.get_defense_value())
        assert ("X" == c.get_defense_value())
        #assert ("pixel_art/road.png" == r.get_image_path())
        #assert ("pixel_art/plain.png" == p.get_image_path())
        #assert ("pixel_art/forest.png" == f.get_image_path())
        #assert ("pixel_art/mountain.png" == m.get_image_path())
        #assert ("pixel_art/city.png" == c.get_image_path())


if __name__ == '__main__':
    unittest.main()
