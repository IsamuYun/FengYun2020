#include <ansi.h>
inherit SKILL;
mapping *tongji = ({
        ([      "tongji":                "�����",
                "tongji_n":             "1",
        ]),
        ([      "tongji":                "������",
                "tongji_n":             "2",
        ]),
        ([      "tongji":                "��ɱ",
                "tongji_n":             "3",
        ]),
        ([      "tongji":                "������",
                "tongji_n":             "4",
        ]),
        ([      "tongji":                "������",
                "tongji_n":             "5",
        ]),
        ([      "tongji":                "��ԯ����",
                "tongji_n":             "6",
        ]),
        ([      "tongji":                "�׿���",
                "tongji_n":             "7",
        ]),
        ([      "tongji":                "������",
                "tongji_n":             "8",
        ]),
        ([      "tongji":                "��ս",
                "tongji_n":             "9",
        ]),
        ([      "tongji":                "ŷ������",
                "tongji_n":             "10",
        ]),
});
mapping query_tongji()
{
        return tongji[random(sizeof(tongji))];
}
