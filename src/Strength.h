//-*- Mode: C++; indent-tabs-mode: nil; tab-width: 2 -*-
/* * Copyright (C) 2015 Brandon Schaefer
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License version 3 as
* published by the Free Software Foundation.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*
* Authored by: Brandon Schaefer <brandontschaefer@gmail.com>
*/

#ifndef STRENGTH
#define STRENGTH

namespace battle_system
{

class Strength
{
public:
  Strength(int strength, int percent_str = 0);

  int GetStrength() const;
  void SetStrength(int strength);

  // TODO Look into increment/decrement functions to simply this
  int GetPercentStrength() const;
  void SetPercentStrength(int percent_str);

  int HitProbBonus() const;
  int DamageBonus()  const;
  int WeightBonus()  const;

private:
  int strength_;
  int percent_str_;
};

} // namespace battle_system

#endif // STRENGTH
