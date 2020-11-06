//Carrega a biblioteca LiquidCrystal
  #include <LiquidCrystal.h>

//Define os pinos que serão utilizados para ligação ao display
  LiquidCrystal lcd(12, 11, 7, 6, 5, 4);


//Definindo as variáveis LED
  int LED1 = A3;
  int LED2 = 2;
  int LED3 = 3;
    
//Definindo as variáveis BOTAO
  int BOTAO1 = 9;
  int BOTAO2 = 8;
  int BOTAO3 = 13;
  int BOTAO4 = 10;

//variáveis auxiliares
  int nivel;                                                    // dificuldade do jogo
  char *aux2[]= {"Iniciar", "Dificuldade", "Pontuacao"};        // menu
  int aux3;                                                     //LEDs aleatorios
  int aux4;
  char *aux5[] = {"LED1 = HIGH","LED2 = HIGH","LED3 = HIGH"};   // comparação das respostas
    
    
  void setup(){
    
  //Define o número de colunas e linhas do LCD
    lcd.begin(16, 2);

  //Setando os pinos
    pinMode (LED1, OUTPUT);
    pinMode (LED2, OUTPUT);
    pinMode (LED3, OUTPUT);
    pinMode (BOTAO1, INPUT_PULLUP);
    pinMode (BOTAO2, INPUT_PULLUP);
    pinMode (BOTAO3, INPUT_PULLUP);
    pinMode (BOTAO4, INPUT_PULLUP);

  //Inicializa a serial  
    Serial.begin(9600);    
  
  //Fonte dos números aleatórios
    randomSeed(analogRead(0));
  
  }//fim do setup

  
  void loop(){

  //Valores das variáveis
    nivel = 3; // "3" é o nivel fácil, é o padrão
    aux3 = 0; //LEDs aleatorios
    

 
  
  //MENU NO DISPLAY 16X2

    //menu inicial
    lcd.clear();          //Limpa a tela
    lcd.setCursor(0,0);   //Posiciona o cursor na coluna 3, linha 0;
    lcd.print("Menu");    //Envia o texto entre aspas para o LCD
    lcd.setCursor(0,1);
    lcd.print(" *START* ");
  
    while(digitalRead(BOTAO4) == LOW){} //espera você pressionar o BOTAO4 para mostrar a próxima página do menu
    delay(500);

    //menu para selecionar a dificuldade
    lcd.clear();           
    lcd.setCursor(0,0);    
    lcd.print("Menu");     
    lcd.setCursor(0,1);
    lcd.print(" Dificuldade > ");
    
    while(digitalRead(BOTAO4) == LOW){}
    delay(500);
  
    while(digitalRead(BOTAO4) == LOW){
      lcd.clear(); 
      lcd.setCursor(0,0);  
      lcd.print("FAC   MED   DIF"); 

      while(digitalRead(BOTAO4) == LOW){
          if(digitalRead(BOTAO1) == HIGH){
              nivel = 3;
              lcd.setCursor(0,1);
              lcd.print("FACIL"); 
               delay(1000);
          } 
           
          if(digitalRead(BOTAO2) == HIGH){
              nivel = 5;
              lcd.setCursor(0,1);
              lcd.print("MEDIO"); 
              delay(1000);
          } 
     
          if(digitalRead(BOTAO3) == HIGH){
              nivel = 8;
              lcd.setCursor(0,1);
              lcd.print("DIFICIL");
              delay(1000); 
          }  // fim do if 
          
      }  //fim do while
      
  }  //fim do while

    //Menu após escolher a dificuldade 
    lcd.clear(); 
    lcd.setCursor(0,0);
    lcd.print("Boa Sorte!");
    lcd.setCursor(0,1);
    lcd.print("3");
    delay(1000);
    lcd.print("2");
    delay(1000);
    lcd.print("1");
    delay(1000);
    lcd.print("COMECOU");
  

    //variaveis dependentes do nivel
      char *aux6[nivel];
      char *aux7[nivel];
    
    
    //Gerar sequencias aleatórias de LEDs
      delay(1000);
  
      for(aux3 = 0; aux3 < nivel; aux3++){
        
        aux4 = random(3);
        
        if(aux4 == 0){
            digitalWrite(LED1, HIGH);
            delay(1000);
            digitalWrite(LED1, LOW);
            delay(500);
        }
        
        if(aux4 == 1){
            digitalWrite(LED2, HIGH);
            delay(1000);
            digitalWrite(LED2, LOW);
            delay(500);
        }
        
        if(aux4 == 2){
            digitalWrite(LED3, HIGH);
            delay(1000);
            digitalWrite(LED3, LOW);
            delay(500);
        }
       
        aux6[aux3] = aux5[aux4];
      }


    //Receber e armazenar os valores dos Botoes
      for(int i = 0; i < nivel; i++){
    
        do{ }
        while(digitalRead(BOTAO1) == LOW && digitalRead(BOTAO2) == LOW && digitalRead(BOTAO3) == LOW);
    
  
        if(digitalRead(BOTAO1) == HIGH){
           digitalWrite(LED1, HIGH);
           delay(100);
           digitalWrite(LED1, LOW);
           aux7[i] = "LED1 = HIGH";
        }
        
        if(digitalRead(BOTAO3) == HIGH){
           digitalWrite(LED3, HIGH);
           delay(100);
           digitalWrite(LED3, LOW);
           aux7[i] = "LED3 = HIGH";
        }
    
        if(digitalRead(BOTAO2) == HIGH){
           digitalWrite(LED2, HIGH);
           delay(100);
           digitalWrite(LED2, LOW);
           aux7[i] = "LED2 = HIGH";
        }
           
       delay(500);
       
     }//fim for

 
    //Comparação entre os LEDs acendidos e os Botões pressionados
       if(nivel == 3){
           if(aux7[0] == aux6[0] && aux7[1] == aux6[1] && aux7[2] == aux6[2]){
              lcd.clear(); 
              lcd.setCursor(0,0);
              lcd.print("Voce Ganhou!");}
           
           else{
              lcd.clear(); 
              lcd.setCursor(0,0);
              lcd.print("Voce Perdeu!");;
           }
       }
      
       if(nivel == 5){
           if(aux7[0] == aux6[0] && aux7[1] == aux6[1] && aux7[2] == aux6[2] && aux7[3] == aux6[3] && aux7[4] == aux6[4]){
              lcd.clear(); 
              lcd.setCursor(0,0);
              lcd.print("Voce Ganhou!");}
           
           else{
              lcd.clear(); 
              lcd.setCursor(0,0);
              lcd.print("Voce Perdeu!");;
           }
       }
      
       if(nivel == 8){
           if(aux7[0] == aux6[0] && aux7[1] == aux6[1] && aux7[2] == aux6[2] && aux7[3] == aux6[3] && aux7[4] == aux6[4] && aux7[5] == aux6[5] && aux7[6] == aux6[6] && aux7[7] == aux6[7]){
              lcd.clear(); 
              lcd.setCursor(0,0);
              lcd.print("Voce Ganhou!");}
           
           else{
              lcd.clear(); 
              lcd.setCursor(0,0);
              lcd.print("Voce Perdeu!");;
           }
       }
 
 
    //Indicador de finalização da rodada 
      int i2;
      delay(1000);
      
      for( i2 = 0;  i2 < 8; i2++){
          digitalWrite(LED1, HIGH);
          digitalWrite(LED2, HIGH);
          digitalWrite(LED3, HIGH);
          delay(100);
          digitalWrite(LED1, LOW);
          digitalWrite(LED2, LOW);
          digitalWrite(LED3, LOW);
          delay(100);
      }
  
  
}// fim do loop
