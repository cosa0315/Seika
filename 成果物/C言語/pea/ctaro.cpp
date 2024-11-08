#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

int point=10;//好感度
int k=1;//クイズの問題数
char s[20];//エンターキーで進むやつ
char name[20];	//プレイヤーの名前

/*関数宣言*/
int c_jannkenn();//C太郎のじゃんけん
int p_jannkenn();//プレイヤーのじゃんけん
void end();//エンディング
void kuizu();//クイズ
void namae();//名前設定

int main(void)
{
	srand((unsigned)time(NULL));
	int a,j,p,c,mozi,ans;//質問答えるよう、ｃ太郎じゃんけん用、プレイヤーじゃんけん用、文字探し、文字探し回答
	//C太郎が自己紹介する
	printf("-----------------------------------------------------------\n");
	printf("                C太郎と友達になろう！の説明書\n");
	printf("遊び方\n");
	printf("    C太郎とおしゃべりしたり、遊んだりして仲良くなるだけ\n");
	printf("    よいと思う選択肢を選んで好感度を上げよう。\n");
	printf("C太郎の説明\n");
	printf("    C太郎は爆発したり、ビームが出たりします。\n");
	printf("    感情豊かで泣いたり怒ったり喜んだりします。\n");
	printf("-----------------------------------------------------------\n");
	printf("エンターキーで物語は進みます。\n");gets(s);
	printf(" ------------------------------\n");
	printf("| |--------------------------| |\n");
	printf("| |                          | |\n");
	printf("| |     □           □      | |\n");
	printf("| |     ■           ■      | |\n");
	printf("| |            ▽            | |\n");
	printf("| |                          | |\n");
	printf("| ---------------------------  |\n");
	printf(" ------------------------------\n");
	
	printf("C太郎：ぼくC太郎！今日は僕と友達になってほしいな\n");gets(s);
	printf("C太郎：君の名前はなんていうの？\n次に入力が来ます\n");gets(s);
	printf("入力してください。\n");
	//プレイヤー名前入力
	//名無しで通らないようにする
	namae();
	//質問1
	printf("C太郎：じゃあ仲良くなるために%sのことを知りたいんだ\n",name);gets(s);
	printf("C太郎：ぼくの質問に答えてね\n");gets(s);
	printf("C太郎：ゲームは好き？(１～３を入力してね)\n１．好き\n２．普通\n３．嫌い\n");
	scanf("%d",&a);
	switch(a){
		case 1:
			printf("%s：好き\n",name);gets(s);
			printf("C太郎：ぼくも好きなんだ！！一緒だね\n");gets(s);//C太郎反応
			point=point+1;//好感度の変化
			break;
		case 2:
			printf("%s：普通\n",name);gets(s);
			printf("C太郎：じゃあ一緒に遊んで好きになってもらいたいな\n");gets(s);//C太郎反応
			break;
		case 3:
			printf("%s：嫌い\n",name);gets(s);
			printf("C太郎：そっか...\n");gets(s);//C太郎反応
			printf("C太郎：じゃあ好きになってもらえるようにまずは\n");gets(s);
			point=point-1;//好感度の変化
			break;
		
		default:
			printf("C太郎：１～３じゃない！！！\n");gets(s);
			//ｃ太郎怒ってバッドエンド
			point=0;
			end();
	}
	//じゃんけん1回目と2回目
	printf("C太郎：ぼくとじゃんけんしようよ！\n");gets(s);
	for(j=0;j<=1;j++){
	printf("C太郎：じゃーんけーん\n");
	printf("出す手を選んでください。\n");
	printf("1.グー\n2.チョキ\n3.パー\n");
	p=p_jannkenn();
	c=c_jannkenn();
	//じゃんけん判定
	if(p>=4){
		printf("C太郎：あれはやかったかな\n");gets(s);
		printf("C太郎：ごめんねもう一回\n");gets(s);
		j--;
	}
	else if(p==c-1 || p==c+2){
		printf("勝ち\n");gets(s);
		printf("C太郎：すごい！！\n");gets(s);
	}
	else if(p==c){
		printf("あいこ\n");gets(s);
		printf("C太郎：引き分けだー\n");gets(s);
	}
	
	else{
		printf("負け\n");gets(s);
		printf("C太郎：わぁ\n");gets(s);
		//ｃ太郎喜びすぎてバッドエンド
		point=1;
		end();
	}
	}
	//じゃんけん3回目（必ず負ける）
	printf("C太郎：じゃあこれで最後だよ！\n");gets(s);
	printf("C太郎：じゃーんけーん\n");gets(s);
	printf("出す手を選んでください。１～３で選ばなかった場合負けになります。\n");
	printf("1.グー\n2.チョキ\n3.パー\n");
	p_jannkenn();
	printf("C太郎\n");
	printf("        ---  ---\n");
	printf("       |   ||   |\n");
	printf("       |   ||   |\n");
	printf("       |   ||   |\n");
	printf("       |   ||   |------\n");
	printf("       |        |   |  |\n");
	printf("       |        |   |  |\n");
	printf(" -------         ------|\n");
	printf("|                      |\n");
	printf("-----------------------\n");
	printf("C太郎：やったー勝てたー\n");gets(s);
	printf("............\n");gets(s);
	printf("C太郎：どうしたの？\n");gets(s);
	printf("１．いや何も\n２．ずるしたよね？\n");
	scanf("%d",&a);
	switch(a){
		case 1:
			printf("%s：いや何も\n",name);gets(s);
			printf("C太郎：ならよかった！\n");gets(s);//C太郎反応
			break;
		case 2:
			printf("%s：ずるしたよね？\n",name);gets(s);
			printf("C太郎：してないもん！！\n");gets(s);//C太郎反応
			//ｃ太郎怒ってバッドエンド
			point=2;
			end();
			break;
		default:
			printf("%s：\n",name);
			printf("C太郎：まあいいや\n");gets(s);
	}
	//質問2
	printf("C太郎：あー楽しかった。\n");gets(s);
	printf("C太郎：のどが渇いてきちゃったぼく動けないから取ってきてくれないかな\n");gets(s);
	printf("この三つがおかれている\n１．オレンジジュース\n２．油\n３．水\n");
	scanf("%d",&a);
	switch(a){
		case 1:
			printf("%s：どうぞ\n",name);gets(s);
			printf("C太郎：ありがとう！！ぼくこれ好きなんだ！\n");gets(s);//C太郎反応
			point=point+1;//好感度の変化
			break;
		case 2:
			printf("%s：どうぞ\n",name);gets(s);
			printf("C太郎：ありがとう！\n");gets(s);//C太郎反応
			point=-1;//好感度の変化
			end();
			break;
		case 3:
			printf("%s：どうぞ\n",name);gets(s);
			printf("C太郎：ありがとう！\n");gets(s);//C太郎反応
			
			break;
		default:
			printf("C太郎：１～３じゃない！！！\n");gets(s);
			//ｃ太郎怒ってバッドエンド
			point=0;
			end();
	}
	//文字探し
	printf("C太郎：じゃあ次はぼくが文字を出すからその中から違う文字を探すゲームだよ\n");gets(s);
	printf("C太郎：じゃあいくよ！\n");gets(s);
	printf("C太郎：第一問\n");gets(s);
	printf("SSSSSSSSSSSSSSSSSSSS\n");
	printf("SSSSSSSSSSSSSSSSSSSS\n");
	printf("SSSSSSSSSSSSSSSSSSSS\n");
	printf("SSSSSSSSSSSSSSSSSSSS\n");
	printf("SSSSSSSSSSSSSSSSSSSS\n");
	printf("SSSSSSSSSSSSSSSSSSSS\n");
	printf("SSSSSSSSSSSSSSSSSSSS\n");
	printf("SSSSSSSSSSSSSSSSSSSS\n");
	printf("SSS5SSSSSSSSSSSSSSSS\n");
	printf("違うものを入力してください。\n");
	scanf("%d",&mozi);
	ans = 5;
	if(mozi==ans){
		printf("C太郎：正解だよ！\n");gets(s);
	}
	else{
		printf("C太郎：違うよ\n");gets(s);
		point=3;
		end();
	}
	printf("C太郎：第二問\n");gets(s);
	printf("llllllllllllllllllll\n");
	printf("llllllllllllllllllll\n");
	printf("llllllllllllllllllll\n");
	printf("llllllllllllllllllll\n");
	printf("llllllllllllllllllll\n");
	printf("lllllllllllllllll1ll\n");
	printf("llllllllllllllllllll\n");
	printf("llllllllllllllllllll\n");
	printf("llllllllllllllllllll\n");
	printf("違うものを入力してください。\n");
	scanf("%d",&mozi);
	ans = 1;
	if(mozi==ans){
		printf("C太郎：正解だよ！\n");gets(s);
	}
	else{
		printf("C太郎：違うよ\n");gets(s);
		point=3;
		end();
	}
	printf("0太郎：第二問\n");gets(s);
	printf("SSSSSSSSSSSSSSSSSSSS\n");
	printf("SSSSSSSSSSSSSSSSSSSS\n");
	printf("SSSSSSSSSSSSSSSSSSSS\n");
	printf("SSSSSSSSSSSSSSSSSSSS\n");
	printf("SSSSSSSSSSSSSSSSSSSS\n");
	printf("SSSSSSSSSSSSSSSSSSSS\n");
	printf("SSSSSSSSSSSSSSSSSSSS\n");
	printf("SSSSSSSSSSSSSSSSSSSS\n");
	printf("SSSSSSSSSSSSSSSSSSSS\n");
	printf("違うものを入力してください。\n");
	scanf("%d",&mozi);
	ans = 0;
	if(mozi==ans){
		printf("C太郎：正解だよ！\n");gets(s);
	}
	else{
		printf("C太郎：違うよ\n");gets(s);
		point=3;
		end();
	}
	//質問３
	printf("C太郎：これも楽しかったねー\n");gets(s);
	printf("C太郎：そういえば\n");
	printf("C太郎：ほかに遊ぶ道具があるはずだからどれか選んでほしいな(１～３を入力してね)\n１．派手な箱\n２．普通の箱\n３．地味な箱\n");
	scanf("%d",&a);
	switch(a){
		case 1:
			printf("%s：持ってきたよ\n",name);gets(s);
			printf("C太郎：開けてみてー\n");gets(s);//C太郎反応
			point=-2;//好感度の変化
			end();
			break;
		case 2:
			printf("%s：持ってきたよ\n",name);gets(s);
			printf("C太郎：開けてみてー\n");gets(s);//C太郎反応
			printf("C太郎：あれ空っぽだったね\n");gets(s);
			printf("C太郎：ざんねーん\n");gets(s);
			break;
		case 3:
			printf("%s：持ってきたよ\n",name);gets(s);
			printf("C太郎：開けてみてー\n");gets(s);//C太郎反応
			point=-3;//好感度の変化
			end();
			break;
		default:
			printf("C太郎：１～３じゃない！！！\n");gets(s);
			//ｃ太郎怒ってバッドエンド
			point=0;
			end();
	}
	//クイズ
	printf("C太郎：じゃあ次はクイズだよ！！\n");gets(s);
	printf("第一問\n");gets(s);
	kuizu();
	printf("第二問\n");gets(s);
	kuizu();
	printf("第三問\n");gets(s);
	kuizu();
	//質問4
	printf("C太郎：ぼくと遊ぶの楽しかった？（１～３で入力してね）\n１．楽しくなかった\n");
	printf("２．楽しかった\n");
	printf("３．普通\n\n");
	scanf("%d",&a);
	switch(a){
		case 1:
			printf("%s：楽しくなかった\n",name);gets(s);
			printf("C太郎：そんなぁ\n");gets(s);//C太郎反応
			point=point-4;//好感度の変化
			end();
			break;
		case 2:
			printf("%s：楽しかった\n",name);gets(s);
			printf("C太郎：よかった！\n");gets(s);//C太郎反応
			point=point+1;//好感度の変化
			break;
		case 3:
			printf("%s：普通\n",name);gets(s);
			printf("C太郎：えー楽しくなかったのー\n");gets(s);//C太郎反応
			
			break;
		default:
			printf("%s：\n",name);
			printf("C太郎：１～３じゃない！！！\n");gets(s);
			//ｃ太郎怒ってバッドエンド
			point=0;
			end();
	}

	//エンディング
	end();
}
//名前処理
void namae()
{
	int x;
	char ctaro[20];
	strcpy(ctaro,"C太郎");
	while(x != 1){
	gets(name);
	printf("C太郎：%sであっているかな？\n",name);gets(s);
	printf("1.いいよ\n");
	printf("2.違うよ\n");
	scanf("%d",&x);
	if(x==1){
		printf("C太郎：%sよろしくね！\n",name);gets(s);
	}
	else{
		printf("じゃあもう一回入力してね\n");
		gets(name);
	}
	}
	if(strcmp(ctaro,name)==0){
		printf("C太郎：ぼくと名前が一緒だね！\n");gets(s);
		strcpy(name,"C");
		printf("C太郎：すごい偶然だね！\n");gets(s);
		printf("C太郎：だけど区別がつきにくいから君のことは%sって呼ぶね\n",name);gets(s);
	}
}
//プレイヤーじゃんけんで何を出すか決める関数
int p_jannkenn()
{
	int you;
	scanf("%d",&you);
	printf("C太郎：ポン！！\n");
	printf("\n");
	printf("\n");
	printf("%s\n",name);
	if(you==1){
			printf("----------------\n");
			printf("|   |   |   |   |\n");
			printf("|   |   |   |   |\n");
			printf("----------------|\n");
			printf("|         |     |\n");
			printf("----------------\n");
			you=1;
	}
	else if(you==2){
			printf(" ---  ---\n");
			printf("|   ||   |\n");
			printf("|   ||   |\n");
			printf("|   ||   |\n");
			printf("|   ||   |------\n");
			printf("|        |   |  |\n");
			printf("|        |   |  |\n");
			printf("----------------|\n");
			printf("|         |     |\n");
			printf("----------------\n");
			you=2;
	}
	else if(you==3){
			printf("        ---  ---  ---  ---\n");
			printf("       |   ||   ||   ||   |\n");
			printf("       |   ||   ||   ||   |\n");
			printf("       |   ||   ||   ||   |\n");
			printf("       |   ||   ||   ||   |\n");
			printf("       |                  |\n");
			printf("       |                  |\n");
			printf(" -------                  |\n");
			printf("|                         |\n");
			printf("--------------------------\n");
			you=3;
	}
	else{
		printf("出さない\n");
	}
	return you;
}
//c太郎じゃんけんで何を出すかを決める関数
int c_jannkenn()
{
	int taro;
	taro=rand()%3;
	printf("\n");
	printf("\n");
	printf("C太郎\n");
	if(taro==1){
			printf("----------------\n");
			printf("|   |   |   |   |\n");
			printf("|   |   |   |   |\n");
			printf("----------------|\n");
			printf("|         |     |\n");
			printf("----------------\n");
			taro=1;
	}
	else if(taro==2){
			printf(" ---  ---\n");
			printf("|   ||   |\n");
			printf("|   ||   |\n");
			printf("|   ||   |\n");
			printf("|   ||   |------\n");
			printf("|        |   |  |\n");
			printf("|        |   |  |\n");
			printf("----------------|\n");
			printf("|         |     |\n");
			printf("----------------\n");
			taro=2;
	}
	else{
			printf("        ---  ---  ---  ---\n");
			printf("       |   ||   ||   ||   |\n");
			printf("       |   ||   ||   ||   |\n");
			printf("       |   ||   ||   ||   |\n");
			printf("       |   ||   ||   ||   |\n");
			printf("       |                  |\n");
			printf("       |                  |\n");
			printf(" -------                  |\n");
			printf("|                         |\n");
			printf("--------------------------\n");
			taro=3;
	}
	return taro;
}
//クイズの関数
void kuizu()
{
	int a;
	char b[20];
	if(k==1){
		printf("C太郎：卵をお酢につけるとどうなるでしょう。（１～３で入力してね）\n１．透明になる\n２．固くなる\n３．鏡のように何でも写すようになる\n");//雑学
		scanf("%d",&a);//１が正解
		switch(a){
		case 1:
			printf("C太郎：正解だよ！！\n");gets(s);//C太郎反応
			break;
		case 2:
			printf("C太郎：違うよ\n");gets(s);//C太郎反応
			point=4;//好感度の変化
			end();
			break;
		case 3:
			printf("C太郎：違うよ\n");gets(s);//C太郎反応
			point=4;//好感度の変化
			end();
			break;
		default:
			printf("C太郎：１～３じゃない！！！\n");gets(s);
			//ｃ太郎怒ってバッドエンド
			point=0;
			end();
	}
	k++;
	}
	else if(k==2){
		printf("C太郎：果物をたくさん乗せたトラックが曲がるときに落としたものは何でしょう。（１～３で入力してね）\n１．アボカド\n２．果物\n３．スピード\n");//ひらめき
		scanf("%d",&a);//３が正解
		switch(a){
		case 1:
			printf("C太郎：違うよ\n");gets(s);//C太郎反応
			point=4;//好感度の変化
			end();
			break;
		case 2:
			printf("C太郎：違うよ\n");gets(s);//C太郎反応
			point=4;//好感度の変化
			end();
			break;
		case 3:
			printf("C太郎：正解だよ！！\n");gets(s);//C太郎反応
			break;
		default:
			printf("C太郎：１～３じゃない！！！\n");gets(s);
			//ｃ太郎怒ってバッドエンド
			point=0;
			end();
	}
	k++;
	}
	else{
		gets(b);
		system("cls");
		printf("C太郎：ぼくはどれでしょう（１～３で入力してね）\n");//C太郎
			printf("   1\n");
			printf(" ------------------------------\n");
			printf("| |--------------------------| |\n");
			printf("| |                          | |\n");
			printf("| |     □           □      | |\n");
			printf("| |     ■           ■      | |\n");
			printf("| |            ▽            | |\n");
			printf("| |                          | |\n");
			printf("| ---------------------------  |\n");
			printf(" ------------------------------\n");
			printf("   2\n");
			printf(" ------------------------------\n");
			printf("| |--------------------------| |\n");
			printf("| |                          | |\n");
			printf("| |     ■           ■      | |\n");
			printf("| |     □           □      | |\n");
			printf("| |            ▽            | |\n");
			printf("| |                          | |\n");
			printf("| ---------------------------  |\n");
			printf(" ------------------------------\n");
			printf("   3\n");
			printf(" ------------------------------\n");
			printf("| |--------------------------| |\n");
			printf("| |                          | |\n");
			printf("| |     □           □      | |\n");
			printf("| |     ■           ■      | |\n");
			printf("| |            △            | |\n");
			printf("| |                          | |\n");
			printf("| ---------------------------  |\n");
			printf(" ------------------------------\n");
			printf("C太郎：上に問題があるよ\n");
			scanf("%d",&a);//１が正解
		switch(a){
		case 1:
			printf("C太郎：正解だよ！！\n");gets(s);//C太郎反応
			break;
		case 2:
			printf("C太郎：違うよ\n");gets(s);//C太郎反応
			point=4;//好感度の変化
			end();
			break;
		case 3:
			printf("C太郎：違うよ\n");gets(s);//C太郎反応
			point=4;//好感度の変化
			end();
			break;
		default:
			printf("C太郎：１～３じゃない！！！\n");gets(s);
			//ｃ太郎怒ってバッドエンド
			point=0;
			end();
	}
	k++;
	}
}
//エンディングがどれになるかを判断する関数
void end()
{
	printf("*-------------------集計中だよ---------------------*\n");
	printf("好感度：%d\n",point);
	if(point==13){
		printf("C太郎：とっても楽しかったよ\nこれからも仲良くしてね\n");gets(s);
		printf("親友end\n");
	}
	else if(point>5){
		printf("C太郎：話すの楽しかったよー\n");gets(s);
		printf("友達end\n");
	}
	else{
		switch(point){
		case 0://入力間違い
			printf("C太郎：エラーが発生しました。エラーが発生しました\n");gets(s);//C太郎反応
			printf("C太郎は混乱して爆発しました。\n");gets(s);
			break;
		
		case 1://じゃんけん負け
			printf("C太郎：やったぁぁぁぁ勝ったぞーーー\n");gets(s);//C太郎反応
			printf("C太郎は喜んでいます。\n");gets(s);
			printf("喜びすぎて爆発しました。\n");gets(s);
			break;
		case -1://質問ミス
			printf("C太郎：ゴクゴクゴク.....\n");gets(s);//C太郎反応
			printf("C太郎：あれ？\n");gets(s);
			printf("C太郎は爆発しました\n");gets(s);
			break;
		case 2://じゃんけん負け
			printf("C太郎：ぼく勝ったもん！！\n");gets(s);//C太郎反応
			printf("C太郎がひかり始めました\n");gets(s);
			printf("C太郎が爆発しました。\n");gets(s);
			break;
		case 3://文字探しミス
			printf("C太郎：すぐ見つけれるようにしてあげるよ！！\n");gets(s);//C太郎反応
			printf("C太郎に改造されました。\n");gets(s);
			break;
		case -2://質問ミス
			printf("中には虫が入っていました。");gets(s);//C太郎反応
			printf("C太郎：わあああああ\n");gets(s);
			printf("C太郎はびっくりして爆発しました。\n");gets(s);
			break;
		case -3://質問ミス
			printf("ほこりがたくさんまいました\n");gets(s);//C太郎反応
			printf("C太郎：クシュン\n");gets(s);
			printf("C太郎はくしゃみをして反動でビームを出しました。\n");gets(s);
			break;
		case 4://クイズミス
			printf("C太郎：ぼくが教えてあげるよ！！\n");gets(s);
			printf("３日間ずっとクイズを叩き込まれました。\n");gets(s);
			break;
		case -4://質問ミス
			printf("C太郎：えーん\n");gets(s);
			printf("C太郎は泣き止みません\n部屋の中に水が溜まってきました\n");gets(s);
			printf("あなたは溺れてしまいました。\n");gets(s);
			break;
		default:
			printf("？\n");
	}

		printf("死亡end\n");
	}
	exit(1);
}