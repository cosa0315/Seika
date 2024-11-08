//
//  15_issue_k22068.c
//  prg1
//
//  Created by k22068kk on 2022/07/07.
//

#include <stdio.h>

#include <stdlib.h>//ランダム関数
#include <time.h>

#define TATE 9 //めいろの縦の数
#define YOKO 10 //めいろの横の数

int memory(int);//記憶力
void meiroCreate();//めいろ
void keybord();//キーボード操作（めいろ内移動移動）
void Event();//イベントますとアイテムます処理
void Enter();//エンターキーを押して話を進める
void Enemy();//敵キャラ
void Boss();//ボス

int meiro[11][11]={{1,1,1,1,1,1,1,1,1,1},
                   {1,2,1,2,1,0,1,0,0,1},
                   {1,0,1,0,1,0,0,0,0,5},
                   {1,0,0,0,1,0,1,1,1,1},
                   {1,0,1,0,1,0,0,0,0,1},
                   {1,0,1,1,1,1,1,1,3,1},
                   {1,0,0,0,2,1,2,0,0,1},
                   {1,1,1,0,1,1,1,1,0,1},
                   {1,0,0,0,0,0,0,0,0,1},
                   {1,1,1,1,1,1,1,1,1,1}
};
int x=0,y=0,px=1,py=8,tempx=0,tempy=0;//px py:プレイヤーの初期位置 tempx tempy:プレイヤーの座標を覚える
int item[4]={'\0'};
int key=0,event=0;
char enter=0;
double memoryTime=2.0;//記憶力クイズの初期制限時間
int AK=10,HP=50,EXP=0;//主人公の初期ステータス

void meiroCreate(){
    
    for(y=0;y<=TATE;y++){
        for(x=0;x<=YOKO;x++){
            if(x==px && y==py){//プレイヤー
                printf("○");
            }
            else if(meiro[y][x]==0){//すすめる場所
                printf(" ");
            }
            else if(meiro[y][x]==1){//壁
                printf("■");
            }
            else if(meiro[y][x]==2){//アイテム
                printf("☆");
            }
            else if(meiro[y][x]==3 || meiro[y][x]==4){//イベントます 3:壁を通れるか 4:ボス
                printf("□");
            }
            else if(meiro[y][x]==5){//ゴール
                printf("▷");
            }
        }
        printf("\n");
    }
    printf("右：d 左：a 上：w 下：s で操作\n");
    printf("○：あなた ☆：アイテム □：イベント G：ゴール\n移動する方向を入力してください:\n");
}
void keybord(){
    key = getchar();
    if(key=='w'){/*上移動*/
        if(meiro[py-1][px]==0 || meiro[py-1][px]==5){
            py--;
        }
        else if(meiro[py-1][px]==2){
            event = 2;
            tempy = py-1;
            tempx = px;
            Event();
        }
        else if(meiro[py-1][px]==3){
            event = 3;
            Event();
        }
        else if(meiro[py-1][px]==4){
            event = 4;
            Event();
        }
    }
    
    else if(key=='s'){/*下移動*/
        if(meiro[py+1][px]==0 || meiro[py+1][px]==5){
            py++;
        }
        else if(meiro[py+1][px]==2){//アイテムだった場合マークを消す
            event = 2;
            tempy = py+1;
            tempx = px;
            Event();
        }
        else if(meiro[py+1][px]==3){//イベントます
            event = 3;
            Event();
        }
        else if(meiro[py+1][px]==4){
            event = 4;
            Event();
        }
    }
    else if(key=='a'){/*左移動*/
        if(meiro[py][px-1]==0 || meiro[py][px-1]==5){
            px--;
        }
        else if(meiro[py][px-1]==2){
            event = 2;
            tempy = py;
            tempx = px-1;
            Event();
        }
        else if(meiro[py][px-1]==3){
            event = 3;
            Event();
        }
        else if(meiro[py][px-1]==4){
            event = 4;
            Event();
        }
    }
    else if(key=='d'){/*右移動*/
        if(meiro[py][px+1]==0 || meiro[py][px+1]==5){
            px++;
        }
        else if(meiro[py][px+1]==2){
            event = 2;
            tempy = py;
            tempx = px+1;
            Event();
        }
        else if(meiro[py][px+1]==3){
            event = 3;
            Event();
        }
        else if(meiro[py][px+1]==4){
            event = 4;
            Event();
        }
    }
}
void Event(){
    int itemID=0;
    switch (event) {
        case 2://アイテムについて
            itemID = rand() % 4 ;
            switch (itemID) {
                case 1://壁を破壊できる
                    printf("ツルハシを手に入れた！");
                    Enter();
                    item[itemID] = 1;
                    meiro[tempy][tempx] = 0;
                    break;
                case 2://攻撃力上昇
                    printf("剣を手に入れた！(攻撃力上昇)");
                    Enter();
                    AK = AK + 3;
                    item[itemID] = 2;
                    meiro[tempy][tempx] = 0;
                    break;
                case 3://時間制限が伸びる
                    printf("賢くなるメガネを手に入れた！(クイズの難易度少し減少)");
                    memoryTime = memoryTime + 3.0;
                    Enter();
                    item[itemID] = 3;
                    meiro[tempy][tempx] = 0;
                    break;
                case 4://体力回復
                    printf("おにぎりを手に入れた！(体力回復)");
                    Enter();
                    HP = HP + 100;
                    item[itemID] = 1;
                    meiro[tempy][tempx] = 0;
                    break;
                default:
                    break;
            }
            break;
        case 3://壁破壊イベ
            if(item[1]!=1 && EXP<150){
                printf("強くなるかツルハシがあれば壊せそうだ");
                Enter();
            }
            else if(item[1]!=0){//ボスと遭遇せず迷宮を脱出できる
                printf("ツルハシで壁を壊せそうだ！\n");
                meiro[5][8] = 0;
                printf("壁を破壊した");
                Enter();
            }
            else if(EXP>=150 && item[1]==0){//この場合ボスと戦う
                printf("時間はかかるが殴って壊せそうだ！\n");
                meiro[5][8] = 0;
                printf("大きな音が鳴らしながら壁は崩壊した");
                meiro[2][8] = 4;
                Enter();
            }
            break;
        case 4://ボスイベ
            printf("さっきの騒音でこの迷宮の主がやってきたようだ！\n");
            printf("眠りを妨げられて怒っている！\n");
            printf("戦うしかない!");
            Enter();
            system("clear");
            Boss();
            meiro[py+1][px]=0;
            break;
        default:
            break;
    }
}
void Enemy(){
    char caractor[5][48] = {{0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0},
                            {0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,1,0,1,1,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0},
                            {0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0},
                            {0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0},
                            {0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0},
    };//1:スライム2:獣3:おばけ4:
    int carainfo[3][3] = {{2,20,10},{5,30,20},{10,40,50}};//敵の攻撃力と体力と経験値
    int encount = 0,caraAKID = 0,caraID = 0,uniqueAK=0;
    int i=0,j=0;
    encount = rand() % 100 ;
    if(encount<=5){//値が5以下のときエンカウントする
        system("clear");
        printf("%d\n",encount);
        printf("   ___ \n");
        printf("  |   |\n");
        printf("  |   |\n");
        printf("  |   |\n");
        printf("  |   |\n");
        printf("  |___|\n");
        printf("   ___ \n");
        printf("  |   |\n");
        printf("  |___|\n");
        Enter();
        system("clear");
        caraID = rand() % 4-1 ;//敵キャラ決め
        while(HP>0 && carainfo[caraID][1]>0){//どちらかの体力が０以下になるまで
            for(i=0;i<5;i++){//敵キャラ表示
                for(j=caraID*16;j<caraID*16+16;j++){
                    if(caractor[i][j]==0){
                        printf(" ");
                    }
                    else if(caractor[i][j]==1){
                        printf("■");
                    }
                }
                printf("\n");
            }
            printf("あなたの体力：%d\n",HP);
            switch (caraID) {
                case 0:
                    printf("スライムが現れた！\n");
                    caraAKID = rand() % 4+1;//ランダムで攻撃する
                    printf("%d\n",caraAKID);
                    Enter();
                    switch(caraAKID){
                        case 1:
                            printf("スライムの攻撃!\n");
                            HP = HP - carainfo[caraID][0];
                            Enter();
                            break;
                        case 2:
                            printf("スライムは勢いよく体当たりをした!\n");
                            HP = HP - carainfo[caraID][0] * 1.5;
                            Enter();
                            break;
                        case 3:
                            printf("スライムはポヨンポヨンと跳ねている!\n");
                            Enter();
                            break;
                        default:
                            printf("攻撃は当たらなかった！\n");
                            break;
                    }
                break;
                case 1:
                    printf("オオカミが現れた！\n");
                    caraAKID = rand() % 4+1;
                    printf("%d\n",caraAKID);
                    Enter();
                    switch(caraAKID){
                        case 1:
                            printf("オオカミの攻撃!\n");
                            HP = HP - carainfo[caraID][0];
                            Enter();
                            break;
                        case 2:
                            printf("オオカミは噛みついてきた!\n");
                            HP = HP - carainfo[caraID][0] * 1.5;
                            Enter();
                            break;
                        case 3:
                            printf("オオカミは毛繕いをしている!\n");
                            Enter();
                            break;
                        default:
                            printf("攻撃は当たらなかった！\n");
                            break;
                    }
                break;
                case 2:
                    printf("お化けが現れた！\n");
                    caraAKID = rand() % 4+1;
                    printf("%d\n",caraAKID);
                    Enter();
                    switch(caraAKID){
                        case 1:
                            printf("お化けの攻撃!\n");
                            HP = HP - carainfo[caraID][0];
                            Enter();
                            break;
                        case 2:
                            printf("お化けは驚かしてきた!\n");
                            HP = HP - carainfo[caraID][0] * 1.5;
                            Enter();
                            break;
                        case 3:
                            printf("お化けの特殊攻撃！\n");
                            Enter();
                            uniqueAK = memory(caraID);
                            if(uniqueAK==1){//特殊攻撃は正解すれば一発で倒せる
                                carainfo[caraID][1] = carainfo[caraID][1] - carainfo[caraID][1];
                            }
                            else if(uniqueAK==2){//不正解の場合大ダメージ
                                HP = HP - carainfo[caraID][0] * 3;
                            }
                            break;
                        default:
                            printf("攻撃は当たらなかった！\n");
                            break;
                    }
                break;
                default:
                    break;
            }
            printf("プレイヤーの攻撃！");
            carainfo[caraID][1] = carainfo[caraID][1] - AK;
            Enter();
            system("clear");
        }
        if(HP>0){
            printf("戦いに勝利した！\n");
            EXP = EXP + carainfo[caraID][2];
            if(EXP%50==0){
                printf("レベルアップ！！\n");
                AK = AK + 5;
                HP = HP + 50;
                printf("体力と攻撃力がアップしました\n");
                Enter();
            }
        }
    }
}
int memory(){
    int hyouzimozi[17] = {0,1,2,3,4,5,6,7,8,9};
    int answer = 0,result=0,same=0,i = 0,j=0,damage=0,randam=0;
    double startTime,endTime;
    double totalTime=0.0;
    same = rand() % 10-1;
    printf("    なにが表示されたか見極めろ！\n");
    Enter();
    system("clear");
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            randam = rand() % 10-1;
            printf("%d",hyouzimozi[randam]);
            if(hyouzimozi[randam]==same){
                result++;
            }
        }
        printf("\n");
    }
    startTime = clock() / CLOCKS_PER_SEC;
    while(1){
        if(totalTime > memoryTime) break;
        endTime = clock() / CLOCKS_PER_SEC;
        totalTime = endTime - startTime;
    }
    system("clear");
    printf("%dは何個ありましたか\n",hyouzimozi[same]);
    scanf("%d",&answer);
    if(answer==result){//正解の場合相手にダメージ
        printf("正解！！\n");
        printf("あいてにダメージ！\n");
        damage = 1;
    }
    else{//不正解の場合自分にダメージ
        printf("不正解！！\n");
        printf("こちらにダメージ！\n");
        damage = 2;
    }
    return (damage);
}

void Boss(){//ボス戦
    char boss[5][13]={{0,0,0,0,1,0,1,0,1,0,0,0},
                      {0,0,0,1,0,1,0,1,0,1,0,0},
                      {0,0,0,1,0,0,0,0,0,1,0,0},
                      {0,0,0,1,0,0,0,0,0,1,0,0},
                      {0,0,0,1,1,1,1,1,1,1,0,0},
    };
    int bossinfo[3] = {15,200,100};
    int bossAKID=0,uniqueAK=0;
    int i=0,j=0;
    while(HP>0 && bossinfo[1]>0){//どちらかの体力が０以下になるまで
        for(i=0;i<5;i++){//敵キャラ表示
            for(j=0;j<13;j++){
                if(boss[i][j]==0){
                    printf(" ");
                }
                else if(boss[i][j]==1){
                    printf("■");
                }
            }
            printf("\n");
        }
        printf("あなたの体力：%d\n",HP);
        bossAKID = rand() % 3+1;
        switch(bossAKID){
            case 1:
                printf("迷宮の主の攻撃!\n");
                HP = HP - bossinfo[0];
                Enter();
                break;
            case 2:
                printf("迷宮の主は勢いよく蹴ってきた!\n");
                HP = HP - bossinfo[0] * 1.5;
                Enter();
                break;
            case 3:
                printf("迷宮の主の特殊攻撃！\n");
                Enter();
                uniqueAK = memory(bossAKID);
                if(uniqueAK==1){
                    bossinfo[1] = bossinfo[1] - AK * 2;
                }
                else if(uniqueAK==2){//不正解の場合大ダメージ
                    HP = HP - bossinfo[0] * 3;
                }
                break;
            default:
                printf("攻撃は当たらなかった！\n");
                break;
        }
        printf("プレイヤーの攻撃！");
        bossinfo[1] = bossinfo[1] - AK;
        Enter();
        system("clear");
    }
    if(HP>0){
        printf("主との戦いに勝利した！\n");
        EXP = EXP + bossinfo[2];
        if(EXP%50==0){
            printf("レベルアップ！！\n");
            AK = AK + 5;
            HP = HP + 50;
            printf("体力と攻撃力がアップしました\n");
            meiro[2][8]=0;
            Enter();
        }
    }
    
}
void Enter(){
    enter = 0;
    while(1){
        printf("(エンターキーで進む)\n");
        enter = getchar();
        if((enter=getchar())=='\n'){
            break;
        }
    }
}
    int main(){
        printf("--------------------\n");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("   迷宮からの脱出\n");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("--------------------\n");
        Enter();
        while(meiro[2][9]!=meiro[py][px] && HP>0){
            system("clear");
            meiroCreate();
            keybord();
            Enemy();
        }
        if(HP>0){
            system("clear");
            printf("\n");
            printf("\n");
            printf("\n");
            printf("\n");
            printf("      クリアおめでとう！\n");
            printf("\n");
            printf("\n");
            printf("\n");
            printf("\n");
        }
        else{
            system("clear");
            printf("\n");
            printf("\n");
            printf("\n");
            printf("\n");
            printf("      GameOver\n");
            printf("     あなたは力尽きた\n");
            printf("\n");
            printf("\n");
            printf("\n");
            printf("また挑戦してね\n");
        }
        return 0;
    }
