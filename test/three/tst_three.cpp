/******************************************************************************
 * MakeQtGame
 * Copyright (C) %YEAR% Andrea Mantovani
 *
 * This file is part of MakeQtGame
 *
 * MakeQtGame is free software: you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * MakeQtGame is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with MakeQtGame. If not, see <http://www.gnu.org/licenses/>.
 *
 *****************************************************************************/

#include <QtTest/QtTest>

// add necessary includes here

class Three : public QObject
{
  Q_OBJECT

private slots:
  void test_case1();
};

void Three::test_case1()
{
  QCOMPARE(1, 1);
}

QTEST_MAIN(Three)

#include "tst_three.moc"
