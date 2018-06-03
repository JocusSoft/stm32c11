/*
 * File: register.h
 * Project: core
 * File Created: Wednesday, 14th June 2017 10:16:14 pm
 * Copyright 2017 - 2018 Denis Mitrofanov (dmitrophanov@gmail.com)
 * Licensed under the Apache License, Version 2.0
 */


#ifndef REGISTER_H
#define	REGISTER_H

#include "register_mask.h"
#include "register_policy.h"


namespace core 
{
    template
    <
       typename mutab_policy,
       unsigned address,
       unsigned offset,
       unsigned width
    >
    struct register_t
    {

       static unsigned read()
       {
          return
             mutab_policy::read(
                reinterpret_cast<volatile unsigned *>(address),
                offset,
                gen_mask<offset, width>::value
             );
       }

       static void write(unsigned value)
       {
          mutab_policy::write(
             reinterpret_cast<volatile unsigned *>(address),
             offset,
             gen_mask<offset, width>::value,
             value
          );
       }

       static void set()
       {
          mutab_policy::set(
             reinterpret_cast<volatile unsigned *>(address),
             gen_mask<offset, width>::value
          );
       }

       static void clear()
       {
          mutab_policy::clear(
             reinterpret_cast<volatile unsigned *>(address),
             gen_mask<offset, width>::value
          );
       }
    };
}

#endif	/* REGISTER_H */

