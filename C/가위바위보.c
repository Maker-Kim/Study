#include <stdio.h>
#include <stdlib.h>

//전역변수 영역 
float Scissors; // 가위
float Rock; //바위
float Paper; //보
int Me; // 내가뭘 낼건지
int Computer; // 컴퓨터가 뭘 낼지
char GameMode; //게임모드 
int Money;      //소지금 
int Win; 	//승리 
int Lose; 	//패배
int Draw;   //무승부 
int Total; //전체 판수 
float Rate; //승률
int Computer_Money; // 컴퓨터 머니 

//메인 영역 
int main(void){
	
	printf("Game Start\n");

	FILE *fp = fopen("savedata.dat", "r+b"); // 세이브 파일 열기
	if (fp == NULL){
		FILE *fp = fopen("savedata.dat", "wb");
		printf("시작 게임머니를 입력 하세요 : ");
		scanf("%d", &Money);
		fwrite( &Money, sizeof(int), 1, fp );
		fwrite( &Total, sizeof(int), 1, fp );
		fwrite( &Rate, sizeof(int), 1, fp );
		fwrite( &Scissors, sizeof(int), 1, fp );
		fwrite( &Rock, sizeof(int), 1, fp );
		fwrite( &Paper, sizeof(int), 1, fp );
		fwrite( &Win, sizeof(int), 1, fp );
		fwrite( &Lose, sizeof(int), 1, fp );
		fwrite( &Draw, sizeof(int), 1, fp );
		fclose(fp);
	}
	
	
	fread( &Money, sizeof(int), 1, fp );
	fread( &Total, sizeof(int), 1, fp );
	fread( &Rate, sizeof(int), 1, fp );
	fread( &Scissors, sizeof(int), 1, fp );
	fread( &Rock, sizeof(int), 1, fp );
	fread( &Paper, sizeof(int), 1, fp );
	fread( &Win, sizeof(int), 1, fp );
	fread( &Lose, sizeof(int), 1, fp );
	fread( &Draw, sizeof(int), 1, fp );

	if (Money <= 0){
		printf("파산 후 재시작 하였습니다. 배팅에 주의 하세요\n");
		printf("재시작 게임머니를 입력 하세요 : ");
		scanf("%d", &Money);
		fwrite( &Money, sizeof(int), 1, fp );
	}
	
	
	
	printf("소지금 : %d\n",Money);
	printf("판수 : %d\n",Total);
	printf("전체 승률: %f\n",Rate);
	
	printf("가위 승률: %f\n",Scissors);
	printf("바위 승률: %f\n",Rock);
	printf("보 승률: %f\n",Paper);
	
	printf("승리 : %d\n",Win);
	printf("패배 : %d\n",Lose);
	printf("무승부 : %d\n",Draw);
	
	
	Mode();
}

//게임 모드 설정 영역 
int Mode(){
	printf("(Y/N) 삼세판 모드 활성화 여부를 입력하세요.\n");
	scanf("%s", &GameMode);
	
	while(1){
		if (GameMode == 'Y'){
			srand((unsigned)time(NULL));
			Computer_Money = rand() %1000000+10000;
			Game1();
			break;
		}
		else if (GameMode == 'N'){
			srand((unsigned)time(NULL));
			Computer_Money = rand() %1000000+10000;
			Game2();
			
			
			break;
		}
		else{
			printf("잘못 입력 하였습니다.");
			printf("(Y/N) 삼세판 모드 활성화 여부를 입력하세요.\n");
			scanf("%s", &GameMode);
		}
	}
}



//삼세판 모드 
int Game1(){
	int Betting = 0;
	int GameWin = 0;
	int GameLose = 0;
	char RePlay,Select;
	
	
	printf("3판 2선승제 입니다. (보상금 x3)\n");
	printf("컴퓨터 돈: %d \n", Computer_Money);
	
	while(1){
		
		Total++;
	
		//배팅 
		if (Betting == 0){
			while(1){
				printf("배팅할 돈을 입력 하세요.\n");
				scanf("%d", &Betting);
				if(Money - Betting < 0 ){
					printf("소유한 돈보다 크게 배팅할 수 없습니다.");
				}
				else{
					printf("배팅머니: %d\n게임을 시작합니다.\n", Betting);
					break; 
				}
			}
			
		}
		
		//승리 
		if (GameWin == 2){
			printf("게임 승리하였습니다.\n");
			Win++; 
			
			Money += Betting * 3;
			Computer_Money -= Betting;
			
			printf("보상금 : %d\n", Betting * 3);
			printf("현재 소지금 : %d\n", Money);
			
			if (Money <= 0){
			printf("파산하였습니다. 게임을 종료 합니다.");
			GameSave();
			break;
			}
			else if (Computer_Money <= 0){
				printf("컴퓨터가 파산 하였습니다. 게임을 종료 합니다.");
				GameSave();
				break;
			}
			
			
			while(1){
				printf("(Y/N)현재 모드를 계속 하시겠습니까?\n");
				scanf("%s", &RePlay);
				
				if (RePlay == 'Y' || RePlay == 'N'){
					break;
				}
				
				else{
					printf("잘못 입력 하였습니다.\n");
				}
			}
			
			
			if (RePlay == 'Y'){
				printf("게임을 계속합니다.\n");
				Game1();
			}
			
			else if (RePlay == 'N'){
				
				while(1){
					printf("(Y/N) 게임을 종료 하시겠습니까?\n");
					printf("ㄴN 입력시 게임 모드 선택창으로 돌아갑니다.\n");		
					scanf("%s", &Select);
					
					if (Select == 'Y' || Select == 'N'){
						break;
					}
					
					else{
						printf("잘못 입력 하였습니다.");
					}
				}
				
				
				if (Select == 'Y'){
					printf("게임을 종료합니다.");
					GameSave();
					break;
				} 
				
				else if (Select == 'N'){
					printf("게임 모드 선택창으로 돌아갑니다.\n");
					Mode();
					break;
				}
			}
		
		}
		
		//패배 
		else if (GameLose == 2){
			
			printf("게임 패배하였습니다.");
			Lose++;
			

			Money -= Betting;
			Computer_Money += Betting * 3;
			
			printf("손실금 : %d\n", Betting);
			printf("현재 소지금 : %d\n", Money);
			
			if (Money <= 0){
				printf("파산하였습니다. 게임을 종료 합니다.");
				GameSave();
				break;
			}
	
			else if (Computer_Money <= 0){
				printf("컴퓨터가 파산 하였습니다. 게임을 종료 합니다.");
				GameSave();
				break;
			}
			
			while(1){
				printf("(Y/N)현재 모드를 계속 하시겠습니까?\n");
				scanf("%s", &RePlay);
				
				if (RePlay == 'Y' || RePlay == 'N'){
					break;
				}
				
				else{
					printf("잘못 입력 하였습니다.\n");
				}
			}
			
			
			if (RePlay == 'Y'){
				printf("게임을 계속합니다.\n");
				Game1();
			}
			
			else if (RePlay == 'N'){
				
				while(1){
					printf("(Y/N) 게임을 종료 하시겠습니까?\n");
					printf("ㄴN 입력시 게임 모드 선택창으로 돌아갑니다.\n");		
					scanf("%s", &Select);
					
					if (Select == 'Y' || Select == 'N'){
						break;
					}
					
					else{
						printf("잘못 입력 하였습니다.");
					}
				}
				
				
				if (Select == 'Y'){
					printf("게임을 종료합니다.");
					GameSave();
					break;
				} 
				
				else if (Select == 'N'){
					printf("게임 모드 선택창으로 돌아갑니다.\n");
					Mode();
					break;
				}
			}
			
		}
			
		
		//난수 초기화 
		srand((unsigned)time(NULL));
		//컴퓨터 가위 or 바위 or 보 
		Computer = rand() %3;

		//나 가위 or 바위 or 보 
		while (1){
			printf("\n0 : 가위 , 1 : 바위, 2 : 보\n");
			scanf("%d", &Me);
			
		
			if (Me == 0 || Me == 1 || Me == 2){
				break;
			}
			else{
				printf("잘못 입력 하였습니다.\n");
			}
			
		}

		
		if (Me == 0) {   //내가 가위를 냈을때
			if (Computer == 0) {
				printf("컴퓨터 : 가위\n");
				printf("=================\n");
				printf("무승부 입니다.\n");
				Draw++;
			}
			else if (Computer == 1) {
				printf("컴퓨터 : 바위\n");
				printf("=================\n");
				printf("패배 하였습니다. \n");
				Lose++;
				GameLose++;
			}
			else {
				printf("컴퓨터 : 보\n");
				printf("=================\n");
				printf("승리 하였습니다.\n");
				Win++;
				Scissors++;
				GameWin++;
			}
		}
		

		else if (Me == 1) {   //내가 바위를 냈을때
			if (Computer == 0) {
				printf("컴퓨터 : 가위\n");
				printf("=================\n");
				printf("승리 하였습니다.\n");
				Win++;
				Rock++;
				GameWin++;
			}
			else if (Computer == 1) {
				printf("컴퓨터 : 바위\n");
				printf("=================\n");
				printf("무승부 입니다.\n");
				Draw++;
			}
			else {
				printf("컴퓨터 : 보\n");
				printf("=================\n");
				printf("패배 하였습니다. \n");
				Lose++;
				GameLose++;
			}
		}
		
		

		else if (Me == 2) {   //내가 보를 냈을때
			if (Computer == 0) {
				printf("컴퓨터 : 가위\n");
				printf("=================\n");
				printf("패배 하였습니다. \n");
				Lose++;
				GameLose++;
			}
			else if (Computer == 1) {
				printf("컴퓨터 : 바위\n");
				printf("=================\n");
				printf("승리 하였습니다.\n");
				Win++;
				Paper++;
				GameWin++;
			}
			else {
				printf("컴퓨터 : 보\n");
				printf("=================\n");
				printf("무승부 입니다.\n");
				Draw++;
			}
		}
}

}

//단판 모드 
int Game2(){
	int Betting = 0;
	int GameWin = 0;
	int GameLose = 0;
	char RePlay,Select;
	
	
	printf("단판제 입니다.(보상금 x2)\n");
	printf("컴퓨터 돈: %d \n", Computer_Money);
	
	while(1){
		Total++;
		//배팅 
		if (Betting == 0){
			while(1){
				printf("배팅할 돈을 입력 하세요.\n");
				scanf("%d", &Betting);
				if(Money - Betting < 0 ){
					printf("소유한 돈보다 크게 배팅할 수 없습니다.");
				}
				else{
					printf("배팅머니: %d\n게임을 시작합니다.\n", Betting);
					break; 
				}
			}
			
		}
		
		//승리 
		if (GameWin == 1){
			printf("게임 승리하였습니다.\n");
			Win++; 
			
			Money += Betting * 2;
			Computer_Money -= Betting;
			
			printf("보상금 : %d\n", Betting * 2);
			printf("현재 소지금 : %d\n", Money);
			
			if (Money <= 0){
			printf("파산하였습니다. 게임을 종료 합니다.");
			GameSave();
			break;
			}
			else if (Computer_Money <= 0){
				printf("컴퓨터가 파산 하였습니다. 게임을 종료 합니다.");
				GameSave();
				break;
			}
			
			
			while(1){
				printf("(Y/N)현재 모드를 계속 하시겠습니까?\n");
				scanf("%s", &RePlay);
				
				if (RePlay == 'Y' || RePlay == 'N'){
					break;
				}
				
				else{
					printf("잘못 입력 하였습니다.\n");
				}
			}
			
			
			if (RePlay == 'Y'){
				printf("게임을 계속합니다.\n");
				Game1();
			}
			
			else if (RePlay == 'N'){
				
				while(1){
					printf("(Y/N) 게임을 종료 하시겠습니까?\n");
					printf("ㄴ(N) 입력시 게임 모드 선택창으로 돌아갑니다.\n");		
					scanf("%s", &Select);
					
					if (Select == 'Y' || Select == 'N'){
						break;
					}
					
					else{
						printf("잘못 입력 하였습니다.");
					}
				}
				
				
				if (Select == 'Y'){
					printf("게임을 종료합니다.");
					GameSave();
					break;
				} 
				
				else if (Select == 'N'){
					printf("게임 모드 선택창으로 돌아갑니다.\n");
					Mode();
					break;
				}
			}
		
		}
		
		//패배 
		else if (GameLose == 1){
			
			printf("게임 패배하였습니다.");
			Lose++;
			

			Money -= Betting;
			Computer_Money += Betting * 2;
			
			printf("손실금 : %d\n", Betting);
			printf("현재 소지금 : %d\n", Money);
			
			if (Money <= 0){
				printf("파산하였습니다. 게임을 종료 합니다.");
				GameSave();
				break;
			}
	
			else if (Computer_Money <= 0){
				printf("컴퓨터가 파산 하였습니다. 게임을 종료 합니다.");
				GameSave();
				break;
			}
			
			while(1){
				printf("(Y/N)현재 모드를 계속 하시겠습니까?\n");
				scanf("%s", &RePlay);
				
				if (RePlay == 'Y' || RePlay == 'N'){
					break;
				}
				
				else{
					printf("잘못 입력 하였습니다.\n");
				}
			}
			
			
			if (RePlay == 'Y'){
				printf("게임을 계속합니다.\n");
				Game1();
			}
			
			else if (RePlay == 'N'){
				
				while(1){
					printf("(Y/N) 게임을 종료 하시겠습니까?\n");
					printf("ㄴ(N) 입력시 게임 모드 선택창으로 돌아갑니다.\n");		
					scanf("%s", &Select);
					
					if (Select == 'Y' || Select == 'N'){
						break;
					}
					
					else{
						printf("잘못 입력 하였습니다.");
					}
				}
				
				
				if (Select == 'Y'){
					printf("게임을 종료합니다.");
					GameSave();
					break;
				} 
				
				else if (Select == 'N'){
					printf("게임 모드 선택창으로 돌아갑니다.\n");
					Mode();
					break;
				}
			}
			
		}
		
		//난수 초기화 
		srand((unsigned)time(NULL));
		//컴퓨터 가위 or 바위 or 보 
		Computer = rand() %3;
		printf("%d",Computer);

		//나 가위 or 바위 or 보 
		while (1){
			printf("\n0 : 가위 , 1 : 바위, 2 : 보\n");
			scanf("%d", &Me);
			
		
			if (Me == 0 || Me == 1 || Me == 2){
				break;
			}
			else{
				printf("잘못 입력 하였습니다.\n");
			}
			
		}

		
		if (Me == 0) {   //내가 가위를 냈을때
			if (Computer == 0) {
				printf("컴퓨터 : 가위\n");
				printf("=================\n");
				printf("무승부 입니다.\n");
				Draw++;
			}
			else if (Computer == 1) {
				printf("컴퓨터 : 바위\n");
				printf("=================\n");
				printf("패배 하였습니다. \n");
				Lose++;
				GameLose++;
			}
			else {
				printf("컴퓨터 : 보\n");
				printf("=================\n");
				printf("승리 하였습니다.\n");
				Win++;
				Scissors++;
				GameWin++;
			}
		}
		

		else if (Me == 1) {   //내가 바위를 냈을때
			if (Computer == 0) {
				printf("컴퓨터 : 가위\n");
				printf("=================\n");
				printf("승리 하였습니다.\n");
				Win++;
				Rock++;
				GameWin++;
			}
			else if (Computer == 1) {
				printf("컴퓨터 : 바위\n");
				printf("=================\n");
				printf("무승부 입니다.\n");
				Draw++;
			}
			else {
				printf("컴퓨터 : 보\n");
				printf("=================\n");
				printf("패배 하였습니다. \n");
				Lose++;
				GameLose++;
			}
		}
		
		

		else if (Me == 2) {   //내가 보를 냈을때
			if (Computer == 0) {
				printf("컴퓨터 : 가위\n");
				printf("=================\n");
				printf("패배 하였습니다. \n");
				Lose++;
				GameLose++;
			}
			else if (Computer == 1) {
				printf("컴퓨터 : 바위\n");
				printf("=================\n");
				printf("승리 하였습니다.\n");
				Win++;
				Paper++;
				GameWin++;
			}
			else {
				printf("컴퓨터 : 보\n");
				printf("=================\n");
				printf("무승부 입니다.\n");
				Draw++;
			}
		}
}
}


int GameSave(){
	printf("Data_Save\n");
	
	Rate = (float)Win / (Win + Lose) * 100;
	
	if (Scissors != 0){
		printf("%f",Scissors);
		Scissors = Scissors / Win * 100;
	}
	if (Rock != 0){
		printf("%f",Rock);
		Rock = Rock / Win * 100;
	}
	if (Paper != 0){
		printf("%f",Paper);
		Paper = Paper / Win * 100;
	}
	
	FILE *fp = fopen("savedata.dat", "wb");
	fwrite( &Money, sizeof(int), 1, fp );
	fwrite( &Total, sizeof(int), 1, fp );
	fwrite( &Rate, sizeof(int), 1, fp );
	fwrite( &Scissors, sizeof(int), 1, fp );
	fwrite( &Rock, sizeof(int), 1, fp );
	fwrite( &Paper, sizeof(int), 1, fp );
	fwrite( &Win, sizeof(int), 1, fp );
	fwrite( &Lose, sizeof(int), 1, fp );
	fwrite( &Draw, sizeof(int), 1, fp );
	fclose(fp);
	
	exit(0);
}
