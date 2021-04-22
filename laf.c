//% gcc laf.c && ./a.out  
#include <stdio.h>



struct subject{
    char* title;
    char* motimonos[16];
} g_subjects[] = {
    { "国語",
        { "国語の教科書", "詩集暗唱ノート", "国語のノート", "漢字スキル", "国語のワーク", "国ワーク(答え)" },
    },
    { "数学",
        { "数学の教科書", "数学のノート", "数学のワーク", "数学のワーク(答え)", "計算反復練習ノート" },
    },
    { "理科",
        { "理科の教科書", "理科のワーク", "理科のワーク(答え)", "理科のノート" },
    },
    { "社会",
        { "社会の教科書", "地理のノート", "歴史の教科書", "社会のワーク" },
    },
    { "英語",
        { "英語の教科書", "英語のワーク", "英語のノート" },
    },
};



int main(){
    struct subject* pSelected[sizeof(g_subjects)/sizeof(g_subjects[0])] = {};
    int             nSelected = 0;

    printf("===========\n");

    int i=0;
    while(i < sizeof(g_subjects)/sizeof(g_subjects[0])){
        printf("%sはありますか？(y/N): ", g_subjects[i].title);
        char c = getc(stdin);
        if(c == 'y' || c == 'Y'){
            pSelected[nSelected++] = &g_subjects[i];
        }
        while(c != '\n') c = getc(stdin);
        ++i;
    }

    int count = 0;

    printf("===========\n");
    printf("持ち物は\n");
    printf("+ 筆箱\n");   ++count;
    printf("+ 下じき\n"); ++count;

    i = 0;
    while(i < nSelected){
        int j = 0;
        while(pSelected[i]->motimonos[j]){
            printf("* %s\n", pSelected[i]->motimonos[j]); ++count;
            ++j;
        }
        ++i;
    }

    printf("-----------\n");
    printf("計 %dこ\n", count);

    return 0;
}


