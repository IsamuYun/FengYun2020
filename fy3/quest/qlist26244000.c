#include <ansi.h>
inherit SKILL;
mapping *quest = ({
        ([      "quest":                "С����",
                "quest_type":           "Ѱ",
                "exp_bonus":            100,
        ]),
        ([      "quest":                "ҹ����",
                "quest_type":           "Ѱ",
                "exp_bonus":            100,
        ]),
        ([      "quest":                "������",
                "quest_type":           "ɱ",
                "exp_bonus":            100,
        ]),
        ([      "quest":                "����",
                "quest_type":           "Ѱ",
                "exp_bonus":            100,
        ]),
        ([      "quest":                "������",
                "quest_type":           "Ѱ",
                "exp_bonus":            100,
        ]),
        ([      "quest":               HIY "�������" NOR,
                "quest_type":           "ɱ",
                "exp_bonus":            100,
        ]),
        ([      "quest":                "��Ѱ��",
                "quest_type":           "ɱ",
                "exp_bonus":            100,
        ]),
        ([      "quest":                RED "С��ɵ�" NOR,
                "quest_type":           "Ѱ",
                "exp_bonus":            100,
        ]),
        ([      "quest":                 HIW "ѩ�׳���" NOR,
                "quest_type":           "Ѱ",
                "exp_bonus":            100,
        ]),
        ([      "quest":                "���˺���ǹ",
                "quest_type":           "Ѱ",
                "exp_bonus":            100,
        ]),

});
mapping query_quest()
{
        return quest[random(sizeof(quest))];
}

