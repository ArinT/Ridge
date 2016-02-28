__author__ = 'Arin'
import unittest
from Models.Tiles.SceneryTile import SceneryTile
from Models.Tiles.GrassTile import GrassTile
from Models.Tiles.WallTile import WallTile
from Models.Tiles.ConcreteTile import ConcreteTile
from Models.Tiles.RoadTile import RoadTile


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
        assert (4 == c.get_defense_value())
        #assert ("PixelArt/road.png" == r.get_image_path())
        #assert ("PixelArt/plain.png" == p.get_image_path())
        #assert ("PixelArt/forest.png" == f.get_image_path())
        #assert ("PixelArt/mountain.png" == m.get_image_path())
        #assert ("PixelArt/city.png" == c.get_image_path())


if __name__ == '__main__':
    unittest.main()
