#ifndef __CYBER_PI__
#define __CYBER_PI__
#include <stdint.h>
#include <Arduino.h>
extern "C"
{
#include <esp32/himem.h>
#include <esp32/spiram.h>
#include "esp_heap_caps.h"
}
#define MALLOC_SPI(a) (ps_malloc(a))
#define MALLOC_INTERNAL(a) (heap_caps_malloc((a),MALLOC_CAP_DMA))
class CyberPi
{
    public:
        CyberPi();
        void begin();
        
        void begin_gpio();

        void begin_lcd();
        void set_lcd_light(bool on);
        void set_lcd_pixel(uint8_t x,uint8_t y,uint16_t color);
        void set_text(uint8_t x,uint8_t y, uint32_t* txt,uint8_t len,uint16_t color, uint8_t size);
        uint16_t color24_to_16(uint32_t rgb);
        uint16_t swap_color(uint16_t color);
        void render_lcd();

        void set_rgb(int idx,uint8_t red,uint8_t greeen,uint8_t blue);

        uint16_t get_gpio();

        int get_joystick_x();
        int get_joystick_y();
        bool get_joystick_pressed();

        bool get_button_a();
        bool get_button_b();
        bool get_button_menu();
        
        uint16_t get_light();

        void begin_gyro();
        float get_gyro_x();
        float get_gyro_y();
        float get_gyro_z();
        float get_acc_x();
        float get_acc_y();
        float get_acc_z();
        float get_roll();
        float get_pitch();

        void begin_sound();
        void set_pitch(uint8_t channel, uint8_t pitch,uint8_t time);
        void set_instrument(uint8_t instrument);
        // void set_raw_sound();

        // void begin_ir();
        // uint8_t get_ir_data();
        // void sent_ir_data(uint8_t c);

        // void begin_microphone(on_record);

        uint8_t* malloc(uint32_t len);

    private:
        static void _on_thread(void *p);
        static void _render_audio(uint8_t *audio_buf,uint16_t audio_buf_len);
};
#endif