#include <ansi.h>
inherit SKILL;
mapping *quest = ({
        ([      "quest":                "����Ҷ��",
                "quest_type":           "Ѱ",
                "time":                 300,
                "exp_bonus":            30,
        ]),
});
mapping query_quest()
{
        return quest[random(sizeof(quest))];
}

