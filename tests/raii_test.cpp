/*
    Copyright (C) 2011 Hugo Arregui, FuDePAN

    This file is part of the MiLi Minimalistic Library.

    MiLi is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    MiLi is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with MiLi.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <string>
#include "mili/mili.h"

using namespace mili;

class file
{
public:
    void write(std::string /*str*/)
    {}
    MOCK_METHOD0(close, void());
};

TEST(RaiiTest, test)
{
    file fi;
    RAII<file, &file::close> rs(fi);
    fi.write("new line in the file");
    EXPECT_CALL(fi, close()).Times(1);
}