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

#include "MoneyPouch.h"

namespace battle_system
{

MoneyPouch::MoneyPouch()
{
  for (int i = 0; i < MoneyType::Size; i++)
    money_[i] = 0;
}

void MoneyPouch::AddMoney(int amount, MoneyType const& type)
{
  money_[type] += amount;
}

int MoneyPouch::WithdrawMoney(int amount, MoneyType const& type)
{
  int withdrawn = 0;

  if (money_[type] >= amount)
    withdrawn = amount;
  else
    withdrawn = money_[type];

  money_[type] -= withdrawn;
  return withdrawn;
}

int MoneyPouch::CheckBalance(MoneyType const& type) const
{
  return money_[type];
}


} // namespace battle_system
