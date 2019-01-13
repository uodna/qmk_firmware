BUILD_DIR=.
TARGET=iris_rev2_uodna-osx-ansi
MCU=atmega32u4

USB=
printf "Detecting USB port, reset your controller now."
ls /dev/tty* > /tmp/1
while [ -z $USB ]; do
  sleep 0.5
  printf "."
  ls /dev/tty* > /tmp/2
  USB=`comm -13 /tmp/1 /tmp/2 | grep -o '/dev/tty.*'`
  mv /tmp/2 /tmp/1
done
echo ""
echo "Detected controller on USB port at $USB"
sleep 1
avrdude -p $MCU -c avr109 -P $USB -U flash:w:$BUILD_DIR/$TARGET.hex

# avrdude: $(BUILD_DIR)/$(TARGET).hex check-size cpfirmware
# $(call EXEC_AVRDUDE)
