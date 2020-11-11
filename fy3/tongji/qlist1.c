#include <ansi.h>
inherit SKILL;
mapping *tongji = ({
        ([      "tongji":                "Àî´ó×ì",
                "tongji_n":             "1",
        ]),
        ([      "tongji":                "ÍÀ½¿½¿",
                "tongji_n":             "2",
        ]),
        ([      "tongji":                "¶ÅÉ±",
                "tongji_n":             "3",
        ]),
        ([      "tongji":                "¹þ¹þ¶ù",
                "tongji_n":             "4",
        ]),
        ([      "tongji":                "Òõ¾ÅÓÄ",
                "tongji_n":             "5",
        ]),
        ([      "tongji":                "ÐùÔ¯Èý¹â",
                "tongji_n":             "6",
        ]),
        ([      "tongji":                "°×¿ªÐÄ",
                "tongji_n":             "7",
        ]),
        ([      "tongji":                "Ïôßäßä",
                "tongji_n":             "8",
        ]),
        ([      "tongji":                "ÌúÕ½",
                "tongji_n":             "9",
        ]),
        ([      "tongji":                "Å·Ñô¶¡µ±",
                "tongji_n":             "10",
        ]),
});
mapping query_tongji()
{
        return tongji[random(sizeof(tongji))];
}
