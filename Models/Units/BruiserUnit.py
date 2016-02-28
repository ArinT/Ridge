__author__ = 'Arin'
import random

from Unit import Unit, m_dist
from Constants import CONST


class BruiserUnit(Unit):
    key = "Bruiser"
    def __init__(self, x, y, map, team):
        max_hp = random.randint(CONST.bruiser_min_hp,
                                CONST.bruiser_max_hp)
        strength = random.randint(CONST.bruiser_min_strength,
                                  CONST.bruiser_max_strength)
        finesse = random.randint(CONST.bruiser_min_finesse,
                                 CONST.bruiser_max_finesse)
        wit = random.randint(CONST.bruiser_min_wit,
                             CONST.bruiser_max_wit)
        style = random.randint(CONST.bruiser_min_style,
                               CONST.bruiser_max_style)
        path = CONST.sh_br_im_path if team == CONST.sharks \
            else CONST.jt_br_im_path
        sfx = CONST.br_at
        super(BruiserUnit, self).__init__(x, y, map, team, max_hp, strength,
                                          finesse, wit, style,
                                          CONST.bruiser_movement, path,sfx)
        self.at_sfx.set_volume(3)
    def calculate_damage(self, unit):
        """Calculates damage for BruiserUnit"""
        base_dmg = self.strength
        reduction = unit.strength * .5 + unit.wit * .5
        return max(base_dmg - reduction, 0)

    def can_attack(self, attack_x, attack_y):
        """Direct attack"""
        s = super(BruiserUnit, self).can_attack(attack_x, attack_y)
        return m_dist(self.x, self.y, attack_x, attack_y) == 1 and s

    def special_attack(self, attack_x, attack_y):
        """Shove.  Pushes enemy unit backward one space. If the space is
        occupied, damage is dealt."""
        if (not self.can_attack(attack_x, attack_y)):
            return False
        direction = self.get_direction(attack_x, attack_y)
        attackee = self.map.unit_at(attack_x, attack_y)
        if direction == "up":
            self.shove("up", attackee)
        elif direction == "right":
            self.shove("right", attackee)
        elif direction == "down":
            self.shove("down", attackee)
        elif direction == "left":
            self.shove("left", attackee)
        return True

    def shove(self, direction, attackee):
        """Shoves unit. If the unit can't move in that direction it takes more
        damage"""
        dmg = self.calculate_damage(attackee)
        if direction == "up":
            if attackee.move(attackee.x, attackee.y - 1):
                attackee.receive_damage(dmg * .5)
            else:
                attackee.receive_damage(dmg * 1.5)
        elif direction == "right":
            if attackee.move(attackee.x + 1, attackee.y):
                attackee.receive_damage(dmg * .5)
            else:
                attackee.receive_damage(dmg * 1.5)
        elif direction == "down":
            if attackee.move(attackee.x, attackee.y + 1):
                attackee.receive_damage(dmg * .5)
            else:
                attackee.receive_damage(dmg * 1.5)
        elif direction == "left":
            if attackee.move(attackee.x - 1, attackee.y):
                attackee.receive_damage(dmg * .5)
            else:
                attackee.receive_damage(dmg * 1.5)

    def get_direction(self, x, y):
        """finds the orientation of the coordinates in relation to caller"""
        if (x + 1 == self.x):
            return "left"
        elif (x - 1 == self.x):
            return "right"
        elif (y - 1 == self.y):
            return "down"
        elif (y + 1 == self.y):
            return "up"
        return None
