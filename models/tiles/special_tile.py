__author__ = 'Arin'
from tile import Tile

path = ["pixel_art/rt.png",
"pixel_art/rtr.png",
"pixel_art/rtl.png",
"pixel_art/rtd.png",
"pixel_art/rtu.png",
"pixel_art/rte1.png",
"pixel_art/rte2.png",
"pixel_art/rte3.png",
"pixel_art/rte4.png"
        ]


class SpecialTile(Tile):
    """Road subclass which calls tile super class to initiate"""
    key = "Inaccessible"
    def __init__(self, x, y, num = 0):
        super(SpecialTile, self).__init__("X", path[num], False, x, y)#hook up image
