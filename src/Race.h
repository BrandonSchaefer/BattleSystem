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

#ifndef RACE
#define RACE

#include <string>
#include <memory>

namespace battle_system
{

class Race
{
public:
  typedef std::shared_ptr<Race> Ptr;

  Race();

  int Weight() const;
  int Height() const;
  int Age() const;

  virtual int BaseMove() const = 0;
  virtual std::string RaceName() const = 0;

protected:
  int weight_;
  int height_;
  int age_;
};

} // namespace battle_system

#endif // RACE
