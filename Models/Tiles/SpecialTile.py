__author__ = 'Arin'
from Tile import Tile

path = ["PixelArt/rt.png",
"PixelArt/rtr.png",
"PixelArt/rtl.png",
"PixelArt/rtd.png",
"PixelArt/rtu.png",
"PixelArt/rte1.png",
"PixelArt/rte2.png",
"PixelArt/rte3.png",
"PixelArt/rte4.png"
        ]


class SpecialTile(Tile):
    """Road subclass which calls tile super class to initiate"""
    key = "Inaccessible"
    def __init__(self, x, y, num = 0):
        super(SpecialTile, self).__init__("X", path[num], False, x, y)#hook up image