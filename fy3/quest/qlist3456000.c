#include <ansi.h>
inherit SKILL;
mapping *quest = ({
        ([      "quest":                "�����",
                "quest_type":           "ɱ",
                "exp_bonus":            80,
        ]),
        ([      "quest":               HIW "������" NOR,
                "quest_type":           "Ѱ",
                "exp_bonus":            80,
        ]),
        ([      "quest":                "�����ʦ",
                "quest_type":           "ɱ",
                "exp_bonus":            80,
        ]),
        ([      "quest":               "�����" ,
                "quest_type":           "Ѱ",
                "exp_bonus":            80,
        ]),
        ([      "quest":                "�ƿ�",
                "quest_type":           "ɱ",
                "exp_bonus":            80,
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "exp_bonus":            80,
        ]),
        ([      "quest":               "��ͭ����" ,
                "quest_type":           "Ѱ",
                "exp_bonus":            80,
        ]),


});
mapping query_quest()
{
        return quest[random(sizeof(quest))];
}

