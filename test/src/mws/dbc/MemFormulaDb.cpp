/*

Copyright (C) 2010-2013 KWARC Group <kwarc.info>

This file is part of MathWebSearch.

MathWebSearch is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

MathWebSearch is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with MathWebSearch.  If not, see <http://www.gnu.org/licenses/>.

*/
/**
 * @file MemFormulaDb.cpp
 *
 */

#include "mws/dbc/MemFormulaDb.hpp"
#include "common/utils/macro_func.h"
#include <iostream>

#include <vector>

using namespace std;
using namespace mws;
using namespace mws::dbc;

struct FormulaInfo {
    CrawlId crawlId;
    FormulaPath formulaPath;
};

vector<FormulaInfo> g_infos = {{ 0, "0"}, {3, "1"}, {2, "4"}};
const int TEST_START_IDX = 1;

static int queryCallback(const CrawlId& crawlId,
                         const FormulaPath& formulaPath) {
    static int i = TEST_START_IDX;

    const FormulaInfo& info = g_infos[i++];

    FAIL_ON(info.crawlId != crawlId);
    FAIL_ON(info.formulaPath != formulaPath);

    cout << "Found: " <<
            " crawlId = " << info.crawlId <<
            " formulaPath = " << info.formulaPath << endl;

    return 0;

fail:
    return -1;
}

int main() {
    FormulaDb* formulaDb = new MemFormulaDb();

    for (auto it = g_infos.begin(); it != g_infos.end(); it++) {
        FAIL_ON(formulaDb->insertFormula(0, it->crawlId, it->formulaPath) != 0);
    }

    FAIL_ON(formulaDb->queryFormula(0, TEST_START_IDX, 2, queryCallback) != 0);

    delete formulaDb;

    return 0;

fail:
    return -1;
}
