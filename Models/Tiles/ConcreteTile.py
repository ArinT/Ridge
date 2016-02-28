__author__ = 'Arin'
from Tile import Tile

path = "PixelArt/cr.png"


class ConcreteTile(Tile):
    """Subclass which calls tile superclass constructor to initiate"""
    key = "Concrete"
    def __init__(self, x, y):
        super(ConcreteTile, self).__init__(1, path, True, x, y)#hook up image