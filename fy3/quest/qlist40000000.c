#include <ansi.h>
inherit SKILL;
mapping *quest = ({
        ([      "quest":                "������",
                "quest_type":           "ɱ",
                "exp_bonus":            150,
        ]),
        ([      "quest":                "֪�������ٷ�",
                "quest_type":           "Ѱ",
                "exp_bonus":            150,
        ]),
        ([      "quest":                "�ƿ�",
                "quest_type":           "ɱ",
                "exp_bonus":            150,
        ]),
        ([      "quest":                "Ҷ�³�",
                "quest_type":           "ɱ",
                "exp_bonus":            150,
        ]),
        ([      "quest":               HIR "����Ѫ��͸�Ĳ���" NOR,
                "quest_type":           "Ѱ",
                "exp_bonus":            150,
        ]),
        ([      "quest":               "���ڹŽ�",
                "quest_type":           "Ѱ",
                "exp_bonus":            150,
        ]),
        ([      "quest":               HIW "���Ѫ�ߵİ���" NOR,
                "quest_type":           "Ѱ",
                "exp_bonus":            150,
        ]),
});
mapping query_quest()
{
        return quest[random(sizeof(quest))];
}

