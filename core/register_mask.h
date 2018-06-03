/*
 * File: register_mask.h
 * Project: core
 * File Created: Wednesday, 14th June 2017 10:16:14 pm
 * Copyright 2017 - 2018 Denis Mitrofanov (dmitrophanov@gmail.com)
 * Licensed under the Apache License, Version 2.0
 */

#ifndef REGISTER_MASK_H
#define	REGISTER_MASK_H

namespace core 
{

template <unsigned width>
struct gen_unshifted_mask
{
   enum {
       value = (gen_unshifted_mask<width - 1>::value << 1) | 1 
   };
};

template <>
struct gen_unshifted_mask<0>
{
   enum { value = 0 };
};

template <unsigned offset, unsigned width>
struct gen_mask
{
   enum { value = gen_unshifted_mask<width>::value << offset };
};

}

#endif	/* REGISTER_MASK_H */

