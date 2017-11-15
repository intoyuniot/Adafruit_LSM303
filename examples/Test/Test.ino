// 这是一个读取传感器LSM303的加速度计值和磁力计值的例子

#include <Adafruit_LSM303.h>

Adafruit_LSM303 lsm;

void setup()
{
    Serial.begin(115200);
    // 如果没有初始化，则USB串口输出相应信息
    if (!lsm.begin())
    {
        Serial.println("Oops ... unable to initialize the LSM303. Check your wiring!");
        while (1);
    }
}

void loop()
{
    lsm.read();  // 读取传感器值
    Serial.print("Accel X: "); Serial.print((int)lsm.accelData.x); Serial.print(" ");
    Serial.print("Y: "); Serial.print((int)lsm.accelData.y);       Serial.print(" ");
    Serial.print("Z: "); Serial.println((int)lsm.accelData.z);     Serial.print(" ");
    Serial.print("Mag X: "); Serial.print((int)lsm.magData.x);     Serial.print(" ");
    Serial.print("Y: "); Serial.print((int)lsm.magData.y);         Serial.print(" ");
    Serial.print("Z: "); Serial.println((int)lsm.magData.z);       Serial.print(" ");
    delay(1000);
}
