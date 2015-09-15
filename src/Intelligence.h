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

#ifndef INTELLIGENCE
#define INTELLIGENCE

namespace battle_system
{

class Intelligence
{
public:
  Intelligence(int intelligence);

  int  GetIntelligence() const;
  void SetIntelligence(int intelligence);

  int ChanceToLearnSpell() const;
  int MaxNumberOfSpellsPerLevel() const;

private:
  int intelligence_;
};

} // namespace battle_system

#endif // INTELLIGENCE
