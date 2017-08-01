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
#include <QCoreApplication>

// add necessary includes here

class Test : public QObject
{
  Q_OBJECT

private slots:
  void test_case1();
  void test_case2();
};

void Test::test_case1()
{
  int a = 0;
  QVERIFY(a == 0);
}

void Test::test_case2()
{
  QCOMPARE("hello", "hello");
}

QTEST_MAIN(Test)

#include "tst_test.moc"
