mapping *quest = ({
        ([      "quest":                "������",
                "quest_type":           "ɱ",
                "time":                  400,
                "exp_bonus":             100,
                "pot_bonus":             30,
                "score" :                4
        ]),
});
mapping query_quest()
{
        return quest[random(sizeof(quest))];
} 