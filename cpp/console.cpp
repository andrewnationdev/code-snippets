// C++ code
//
#include <Adafruit_LiquidCrystal.h>

int seconds = 0;
const int start_btn = 2;
const int stop_btn = 3;
const int reset_btn = 4;

const int up_btn = 5;
const int down_btn = 6;
const int left_btn = 7;
const int right_btn = 8;

bool is_game_mode = false;
bool is_main_menu = false;

int posx = 1;
int posy = 1;

Adafruit_LiquidCrystal lcd_1(0);

void setup()
{
  lcd_1.begin(16, 2);
  
  pinMode(start_btn, INPUT_PULLUP);
  pinMode(stop_btn, INPUT_PULLUP);
  pinMode(reset_btn, INPUT_PULLUP);
  pinMode(up_btn, INPUT_PULLUP);
  pinMode(down_btn, INPUT_PULLUP);
  pinMode(left_btn, INPUT_PULLUP);
  pinMode(right_btn, INPUT_PULLUP);
  
  Serial.begin(9600);
}

void update(){
  	/*int reset_btn_state = digitalRead(reset_btn);
  
  	if (reset_btn_state == LOW) {
    	reset_all();
      	
      	return;
  	}*/
  
	lcd_1.clear();
}

void draw(){
	lcd_1.setCursor(posx, posy);
  	lcd_1.print("#");
}

void game_loop(){
  while(is_game_mode){
    int up_btn_state = digitalRead(up_btn);
    int down_btn_state = digitalRead(down_btn);
    int left_btn_state = digitalRead(left_btn);
    int right_btn_state = digitalRead(right_btn);
    
    if (up_btn_state == LOW) {
    	//lcd_1.print("W");
      
      	if (posy > 1) posy--;
  	}
    
    if (down_btn_state == LOW) {
    	//lcd_1.print("S");
      
      	if (posy < 1) posy++;
  	}
    
    if (left_btn_state == LOW) {
    	//lcd_1.print("A");
      
      	if (posx > 0) posx--;
  	}
    
    if (right_btn_state == LOW) {
    	//lcd_1.print("D");
      
      	if (posx < 16) posx++;
  	}
    
  	update();
    draw();
  }
  
  return;
}

void reset_all(){
  lcd_1.clear();
  is_game_mode = false;
  is_main_menu = true;
}

void main_menu(){
  lcd_1.clear();
  lcd_1.print("Game: Runner!");
  lcd_1.setCursor(2, 1);
  lcd_1.print("Press START");
  is_main_menu = true;
  
  while(true){
    int start_btn_state = digitalRead(start_btn);
  
    if (start_btn_state == LOW && !is_game_mode) {
      Serial.println("Botão pressionado!");
      lcd_1.clear();
      lcd_1.print("LOADING...");
      is_game_mode = true;
      delay(200);
      game_loop();
      break;
    }
  }
}

void loop()
{
  int start_btn_state = digitalRead(start_btn);
  int stop_btn_state = digitalRead(stop_btn);
  int reset_btn_state = digitalRead(reset_btn);
  
  if (start_btn_state == LOW && !is_main_menu) {
    Serial.println("Botão pressionado!");
    lcd_1.print(">>GAMESTATION<<");
    delay(400);
    main_menu();
  }
  
  if (stop_btn_state == LOW) {
    lcd_1.clear();
    lcd_1.print("Bye bye!");
    delay(400);
    lcd_1.clear();
    return;
  }
  
  if (reset_btn_state == LOW) {
    lcd_1.clear();
  }
}
