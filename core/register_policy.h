/*
 * File: register_policy.h
 * Project: core
 * File Created: Wednesday, 14th June 2017 10:16:14 pm
 * Copyright 2017 - 2018 Denis Mitrofanov (dmitrophanov@gmail.com)
 * Licensed under the Apache License, Version 2.0
 */

#ifndef REGISTER_POLICY_H
#define	REGISTER_POLICY_H

namespace core 
{

struct ro_regp
{
   static unsigned read(volatile unsigned * mmr, unsigned offset, unsigned mask)
   {
       return (*mmr & mask) >> offset; 
   } 
};

struct wo_regp
{
   static void write(volatile unsigned * mmr, unsigned offset, unsigned mask, unsigned value)
   { 
       *mmr = ((value << offset) & mask); 
   }

   static void set(volatile unsigned * mmr, unsigned mask)
   { 
       *mmr = mask; 
   }
};

struct rw_regp : ro_regp
{
   static void write(volatile unsigned * mmr, unsigned offset, unsigned mask, unsigned value)
   { 
       *mmr = (*mmr & ~mask) | ((value << offset) & mask); 
   }

   static void set(volatile unsigned * mmr, unsigned mask)
   { 
       *mmr |= mask; 
   }

   static void clear(volatile unsigned * mmr, unsigned mask)
   { 
       *mmr &= ~mask; 
   }
};

}

#endif	/* REGISTER_POLICY_H */

