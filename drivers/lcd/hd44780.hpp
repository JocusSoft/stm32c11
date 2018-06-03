/*
 * File: hd44780.hpp
 * Project: lcd
 * File Created: Wednesday, 14th June 2017 10:16:14 pm
 * Copyright 2017 - 2018 Denis Mitrofanov (dmitrophanov@gmail.com)
 * Licensed under the Apache License, Version 2.0
 */


#pragma once

#include <inttypes.h>

#include "peripherals/pin.hpp"
#include "peripherals/clock.hpp"
#include "peripherals/systick.hpp"

template<typename rs_pin, typename en_pin, 
        typename d0_pin, typename d1_pin,
        typename d2_pin, typename d3_pin,
        uint8_t  cols, uint8_t rows>
class hd44780
{
    public:
        enum {
          LCD_CLEARDISPLAY=0x01,
          LCD_RETURNHOME=0x02,
          LCD_ENTRYMODESET=0x04,
          LCD_DISPLAYCONTROL=0x08,
          LCD_CURSORSHIFT=0x10,
          LCD_FUNCTIONSET=0x20,
          LCD_SETCGRAMADDR=0x40,
          LCD_SETDDRAMADDR=0x80,

          // flags for display entry mode
          LCD_ENTRYRIGHT=0x00,
          LCD_ENTRYLEFT=0x02,
          LCD_ENTRYSHIFTINCREMENT=0x01,
          LCD_ENTRYSHIFTDECREMENT=0x00,

          // flags for display on/off control
          LCD_DISPLAYON=0x04,
          LCD_DISPLAYOFF=0x00,
          LCD_CURSORON=0x02,
          LCD_CURSOROFF=0x00,
          LCD_BLINKON=0x01,
          LCD_BLINKOFF=0x00,

          // flags for display/cursor shift
          LCD_DISPLAYMOVE=0x08,
          LCD_CURSORMOVE=0x00,
          LCD_MOVERIGHT=0x04,
          LCD_MOVELEFT=0x00,

          // flags for function set
          LCD_2LINE=0x08,
          LCD_1LINE=0x00,
          LCD_5x10DOTS=0x04,
          LCD_5x8DOTS=0x00
        };
        
        static void Init()
        {
            _function = LCD_1LINE | LCD_5x8DOTS;
            if(rows > 1) _function |= LCD_2LINE;
            systick::delay_ms(50);
            rs_pin::clr();
            en_pin::clr();
            
            write_bits(3);
            systick::delay_ms(45);
            
            write_bits(3);
            systick::delay_ms(45);
            
            write_bits(3);
            systick::delay_ms(2);
            
            write_bits(2);
            
            command(LCD_FUNCTIONSET | _function);
            
            _control = LCD_DISPLAYON | LCD_CURSOROFF | LCD_BLINKOFF;
            set_display(true);
            
            clear();
            
            _mode = LCD_ENTRYLEFT | LCD_ENTRYSHIFTDECREMENT;
            
            command(LCD_ENTRYMODESET | _mode);
        }
        
        static void clear()
        {
            command(LCD_CLEARDISPLAY);
            systick::delay_ms(1);
        }
        
        static void scroll(bool left)
        {
            if(left)
            {
                command(LCD_CURSORSHIFT | LCD_DISPLAYMOVE | LCD_MOVELEFT);
            }else
            {
                command(LCD_CURSORSHIFT | LCD_DISPLAYMOVE | LCD_MOVERIGHT);
            }
        }
        
        static void move(uint8_t col,uint8_t row)
        {
            const int row_offsets[]= { 0x00,0x40,0x14,0x54 };
            if(row>rows)
                row=rows-1; 

            command(LCD_SETDDRAMADDR | (col+row_offsets[row]));
        }
        
        static void set_cursor(bool on)
        {
            if(on)
            {
                _control|=LCD_CURSORON;                
            }else
            {
                _control&=~LCD_CURSORON;
            }
            command(LCD_DISPLAYCONTROL | _control);
        }
        
        static void set_blink(bool on)
        {
            if(on)
            {
                _control|=LCD_BLINKON;                
            }else
            {
                _control&=~LCD_BLINKON;
            }
            command(LCD_DISPLAYCONTROL | _control);
        }
        
        static void set_direction(bool left)
        {
            if(left)
            {
                _mode|=LCD_ENTRYLEFT;
            }else
            {
                _mode&=~LCD_ENTRYLEFT;
            }
            command(LCD_ENTRYMODESET | _mode);
        }
        
        static void set_autoscroll(bool on)
        {
            if(on)
            {
                _mode|=LCD_ENTRYSHIFTINCREMENT;
            } else
            {
                _mode&=~LCD_ENTRYSHIFTINCREMENT;
            }
            command(LCD_ENTRYMODESET | _mode);
        }
        
        static void set_display(bool on)
        {
            if(on)
            {
                _control |=LCD_DISPLAYON;
            }else
            {
                _control &=~LCD_DISPLAYON;
            }
            
            command(LCD_DISPLAYCONTROL | _control);
        }
        
        static void command(uint8_t val)
        {
            send(val,false);
        }
        
        static void write(uint8_t val)
        {
            send(val,true);
        }
    private:
        
        static uint8_t _function;
        static uint8_t _control;
        static uint8_t _mode;
        
        static uint8_t _cline;
        
        static void send(uint8_t val,uint8_t mode)
        {
            rs_pin::write(mode);
            
            write_bits(val >> 4);
            write_bits(val);
        }
        
        static void write_bits(uint8_t val)
        {
            d0_pin::write((val) & 1);
            d1_pin::write((val >> 1) & 1);
            d2_pin::write((val >> 2) & 1);
            d3_pin::write((val >> 3) & 1);
            
            strobe();
        }
        
        static void strobe()
        {
            en_pin::clr();
            en_pin::set();
            systick::delay_us(1);
            en_pin::clr();
            systick::delay_us(1);
        }
};

template<typename rs_pin, typename en_pin, 
        typename d0_pin, typename d1_pin,
        typename d2_pin, typename d3_pin,
        uint8_t  cols, uint8_t rows>
uint8_t hd44780<rs_pin,en_pin,d0_pin,d1_pin,d2_pin,d3_pin,cols,rows>::_function=0;

template<typename rs_pin, typename en_pin, 
        typename d0_pin, typename d1_pin,
        typename d2_pin, typename d3_pin,
        uint8_t  cols, uint8_t rows>
uint8_t hd44780<rs_pin,en_pin,d0_pin,d1_pin,d2_pin,d3_pin,cols,rows>::_control=0;

template<typename rs_pin, typename en_pin, 
        typename d0_pin, typename d1_pin,
        typename d2_pin, typename d3_pin,
        uint8_t  cols, uint8_t rows>
uint8_t hd44780<rs_pin,en_pin,d0_pin,d1_pin,d2_pin,d3_pin,cols,rows>::_mode=0;

template<typename rs_pin, typename en_pin, 
        typename d0_pin, typename d1_pin,
        typename d2_pin, typename d3_pin,
        uint8_t  cols, uint8_t rows>
uint8_t hd44780<rs_pin,en_pin,d0_pin,d1_pin,d2_pin,d3_pin,cols,rows>::_cline=0;