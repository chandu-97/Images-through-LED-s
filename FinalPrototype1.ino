/*
    Multiplexing 7x5 matrix 7 has transistors and resistance.5 is directly
connected to digital pins of the arduino.... :)
            8  9  10  11  12  
        
        1     
        2
        3
        4
        5
        6
        7
        
*/
//example
//A[3][4] = { { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 } };
//image[7][5] = { { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 } };

//int image[7][5] = { { 0, 0, 0, 0, 0 }, { 0, 1, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 1, 0 }, { 1, 0, 0, 0, 1 }, { 0, 0, 0, 1, 0 }, { 0, 0, 1, 0, 0 } };

//A[7][5] = { { 0, 0, 1, 0, 0 }, { 0, 1, 0, 1, 0 }, { 1, 0, 0, 0, 1 }, { 1, 1, 1, 1, 1 }, { 1, 0, 0, 0, 1 }, { 1, 0, 0, 0, 1 }, { 1, 0, 0, 0, 1 } };
//B[7][5] = { { 1, 1, 1, 1, 1 }, { 1, 0, 0, 0, 1 }, { 1, 0, 0, 0, 1 }, { 1, 1, 1, 1, 1 }, { 1, 0, 0, 0, 1 }, { 1, 0, 0, 0, 1 }, { 1, 1, 1, 1, 1 } };
//C[7][5] = { { 1, 1, 1, 1, 1 }, { 1, 0, 0, 0, 0 }, { 1, 0, 0, 0, 0 }, { 1, 0, 0, 0, 0 }, { 1, 0, 0, 0, 0 }, { 1, 0, 0, 0, 0 }, { 1, 1, 1, 1, 1 } };
//D[7][5] = { { 1, 1, 1, 1, 0 }, { 1, 0, 0, 0, 1 }, { 1, 0, 0, 0, 1 }, { 1, 0, 0, 0, 1 }, { 1, 0, 0, 0, 1 }, { 1, 0, 0, 0, 1 }, { 1, 1, 1, 1, 0 } };
//E[7][5] = { { 1, 1, 1, 1, 1 }, { 1, 0, 0, 0, 0 }, { 1, 0, 0, 0, 0 }, { 1, 1, 1, 1, 1 }, { 1, 0, 0, 0, 0 }, { 1, 0, 0, 0, 0 }, { 1, 1, 1, 1, 1 } };
//F[7][5] = { { 1, 1, 1, 1, 1 }, { 1, 0, 0, 0, 0 }, { 1, 0, 0, 0, 0 }, { 1, 1, 1, 1, 1 }, { 1, 0, 0, 0, 0 }, { 1, 0, 0, 0, 0 }, { 1, 0, 0, 0, 0 } };

//basic joystick

int image[14][10] = { { 0, 0, 1, 0, 0 , 0, 1, 0, 1, 0 }, { 1, 0, 0, 0, 1 , 1, 1, 1, 1, 1 }, { 1, 0, 0, 0, 1 , 1, 0, 0, 0, 1 }, { 1, 0, 0, 0, 1 , 1, 1, 1, 1, 1 }, { 1, 0, 0, 0, 1 , 1, 0, 0, 0, 1 }, { 1, 1, 1, 1, 1 , 1, 0, 0, 0, 1 }, { 1, 0, 0, 0, 1 , 1, 1, 1, 1, 1 }, { 1, 1, 1, 1, 1 , 1, 0, 0, 0, 0 }, { 1, 0, 0, 0, 0 , 1, 0, 0, 0, 0 }, { 1, 0, 0, 0, 0 , 1, 0, 0, 0, 0 }, { 1, 1, 1, 1, 1 , 1, 1, 1, 1, 0 }, { 1, 0, 0, 0, 1 , 1, 0, 0, 0, 1 }, { 1, 0, 0, 0, 1 , 1, 0, 0, 0, 1 }, { 1, 0, 0, 0, 1 , 1, 1, 1, 1, 0 } };

int joystickx=0;//pin1
int joysticky=1;//pin2
int readjoyx=0;//initialization
int readjoyy=0;//initialization
int buttonpin=13;//pin13
int buttonvalue=0;//initialization

int centerX;
int centerY;
void setup(){
	Serial.begin(9600);
	pinMode(buttonpin,INPUT_PULLUP);

        for(int i=1 ; i<=12 ; i++){
              pinMode( i , OUTPUT);
        }
        
        for(int i=1 ; i<=12 ; i++){
              digitalWrite( i , OUTPUT);
        }
}

void loop(){
	readjoyx=analogRead(joystickx);//read value of x
	readjoyy=analogRead(joysticky);	//read value of y
	buttonvalue=digitalRead(buttonpin);
      
        centerX=map(readjoyx,0,1023,0,14);
        centerY=map(readjoyy,0,1023,0,10);
        
        if(centerX<4)centerX=4;
        if(centerX>10)centerX=10;
        
        if(centerY<3)centerY=3;
        if(centerY>7)centerY=7;
        
        for(int j=8 ; j<=12 ; j++ ){
    
              digitalWrite( j , HIGH );
    
            for(int k=1 ; k<=7 ; k++ ){
                if( image[centerX+k-4-1][centerY+j-3-8] == 1 ){
                digitalWrite( k , HIGH );
            }
        }
    
        delay(5);
    
        for(int l=1 ; l<=7 ; l++ ){
            digitalWrite( l , LOW );
        }
    
        digitalWrite( j , LOW );
    
        }
	Serial.print("X val:");
	Serial.print(readjoyx);
	Serial.print("Y val:");
	Serial.print(readjoyy);
	Serial.print('\n');
}
