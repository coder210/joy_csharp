//#include "../mono.h"
//#include "joy/mathx.h"
//#include "csclib.h"
//
//
//void csopen_math()
//{
//        livS_mono_add_internal_call("Joy.FP::FromFloat", fp_from_float);
//        livS_mono_add_internal_call("Joy.FP::ToFloat", fp_to_float);
//        livS_mono_add_internal_call("Joy.FP::MinValue", fp_min_value);
//        livS_mono_add_internal_call("Joy.FP::MaxValue", fp_max_value);
//        livS_mono_add_internal_call("Joy.FP::Add", fp_add);
//        livS_mono_add_internal_call("Joy.FP::Sub", fp_sub);
//        livS_mono_add_internal_call("Joy.FP::Mul", fp_mul);
//        livS_mono_add_internal_call("Joy.FP::Div", fp_div);
//        livS_mono_add_internal_call("Joy.FP::Abs", fp_abs);
//        livS_mono_add_internal_call("Joy.FP::Sqrt", fp_sqrt);
//        livS_mono_add_internal_call("Joy.FP::Sin", fp_sin);
//        livS_mono_add_internal_call("Joy.FP::Cos", fp_cos);
//        livS_mono_add_internal_call("Joy.FP::Zero", fp_zero);
//        livS_mono_add_internal_call("Joy.FP::Half", fp_half);
//        livS_mono_add_internal_call("Joy.FP::One", fp_one);
//        livS_mono_add_internal_call("Joy.FP::Pi", fp_pi);
//        livS_mono_add_internal_call("Joy.FP::Max", fp_max);
//        livS_mono_add_internal_call("Joy.FP::Min", fp_min);
//        livS_mono_add_internal_call("Joy.FP::Pow2", fp_pow2);
//        livS_mono_add_internal_call("Joy.FP::Sign", fp_sign);
//        livS_mono_add_internal_call("Joy.FP::Clamp", fp_clamp);
//        livS_mono_add_internal_call("Joy.FP::Lerp", fp_lerp);
//
//        livS_mono_add_internal_call("Joy.FT::FromFloat", ft_from_float);
//        livS_mono_add_internal_call("Joy.FT::MinValue", ft_min_value);
//        livS_mono_add_internal_call("Joy.FT::MaxValue", ft_max_value);
//        livS_mono_add_internal_call("Joy.FT::Add", ft_add);
//        livS_mono_add_internal_call("Joy.FT::Sub", ft_sub);
//        livS_mono_add_internal_call("Joy.FT::Mul", ft_mul);
//        livS_mono_add_internal_call("Joy.FT::Div", ft_div);
//        livS_mono_add_internal_call("Joy.FT::Abs", ft_abs);
//        livS_mono_add_internal_call("Joy.FT::Sqrt", ft_sqrt);
//        livS_mono_add_internal_call("Joy.FT::Sin", ft_sin);
//        livS_mono_add_internal_call("Joy.FT::Cos", ft_cos);
//        livS_mono_add_internal_call("Joy.FT::Zero", ft_zero);
//        livS_mono_add_internal_call("Joy.FT::Half", ft_half);
//        livS_mono_add_internal_call("Joy.FT::One", ft_one);
//        livS_mono_add_internal_call("Joy.FT::PI", ft_pi);
//        livS_mono_add_internal_call("Joy.FT::Max", ft_max);
//        livS_mono_add_internal_call("Joy.FT::Min", ft_min);
//        livS_mono_add_internal_call("Joy.FT::Pow2", ft_pow2);
//        livS_mono_add_internal_call("Joy.FT::Sign", ft_sign);
//        livS_mono_add_internal_call("Joy.FT::Clamp", ft_clamp);
//        livS_mono_add_internal_call("Joy.FT::Lerp", ft_lerp);
//
//
//        livS_mono_add_internal_call("Joy.Vec2::Negate", vec2_negate);
//        livS_mono_add_internal_call("Joy.Vec2::Dot", vec2_dot);
//        livS_mono_add_internal_call("Joy.Vec2::Cross", vec2_cross);
//        livS_mono_add_internal_call("Joy.Vec2::Cross2", vec2_cross2);
//        livS_mono_add_internal_call("Joy.Vec2::Cross3", vec2_cross3);
//        livS_mono_add_internal_call("Joy.Vec2::Add", vec2_add);
//        livS_mono_add_internal_call("Joy.Vec2::Sub", vec2_sub);
//        livS_mono_add_internal_call("Joy.Vec2::Scale", vec2_scale);
//        livS_mono_add_internal_call("Joy.Vec2::Abs", vec2_abs);
//        livS_mono_add_internal_call("Joy.Vec2::LengthSquared", vec2_length_squared);
//        livS_mono_add_internal_call("Joy.Vec2::Length", vec2_length);
//        livS_mono_add_internal_call("Joy.Vec2::Normalize", vec2_normalize);
//        livS_mono_add_internal_call("Joy.Vec2::Normal", vec2_normal);
//        livS_mono_add_internal_call("Joy.Vec2::Rotate", vec2_rotate);
//        livS_mono_add_internal_call("Joy.Vec2::Lerp", vec2_lerp);
//        livS_mono_add_internal_call("Joy.Vec2::Distance", vec2_distance);
//
//        livS_mono_add_internal_call("Joy.Vec2F::Negate", vec2f_negate);
//        livS_mono_add_internal_call("Joy.Vec2F::Dot", vec2f_dot);
//        livS_mono_add_internal_call("Joy.Vec2F::Cross", vec2f_cross);
//        livS_mono_add_internal_call("Joy.Vec2F::Cross2", vec2f_cross2);
//        livS_mono_add_internal_call("Joy.Vec2F::Cross3", vec2f_cross3);
//        livS_mono_add_internal_call("Joy.Vec2F::Add", vec2f_add);
//        livS_mono_add_internal_call("Joy.Vec2F::Sub", vec2f_sub);
//        livS_mono_add_internal_call("Joy.Vec2F::Scale", vec2f_scale);
//        livS_mono_add_internal_call("Joy.Vec2F::Abs", vec2f_abs);
//        livS_mono_add_internal_call("Joy.Vec2F::LengthSquared", vec2f_length_squared);
//        livS_mono_add_internal_call("Joy.Vec2F::Length", vec2f_length);
//        livS_mono_add_internal_call("Joy.Vec2F::Normalize", vec2f_normalize);
//        livS_mono_add_internal_call("Joy.Vec2F::Normal", vec2f_normal);
//        livS_mono_add_internal_call("Joy.Vec2F::Rotate", vec2f_rotate);
//        livS_mono_add_internal_call("Joy.Vec2F::Lerp", vec2f_lerp);
//        livS_mono_add_internal_call("Joy.Vec2F::Distance", vec2f_distance);
//
//        livS_mono_add_internal_call("Joy.Vec3F::Negate", vec3f_negate);
//        livS_mono_add_internal_call("Joy.Vec3F::Dot", vec3f_dot);
//        livS_mono_add_internal_call("Joy.Vec3F::Cross", vec3f_cross);
//        livS_mono_add_internal_call("Joy.Vec3F::Add", vec3f_add);
//        livS_mono_add_internal_call("Joy.Vec3F::Sub", vec3f_sub);
//        livS_mono_add_internal_call("Joy.Vec3F::Scale", vec3f_scale);
//        livS_mono_add_internal_call("Joy.Vec3F::Abs", vec3f_abs);
//        livS_mono_add_internal_call("Joy.Vec3F::LengthSquared", vec3f_square_length);
//        livS_mono_add_internal_call("Joy.Vec3F::Length", vec3f_length);
//        livS_mono_add_internal_call("Joy.Vec3F::Normalize", vec3f_normalize);
//        livS_mono_add_internal_call("Joy.Vec3F::Lerp", vec3f_lerp);
//        livS_mono_add_internal_call("Joy.Vec3F::Distance", vec3f_distance);
//
//        livS_mono_add_internal_call("Joy.Mat22::Abs", mat22_abs);
//        livS_mono_add_internal_call("Joy.Mat22::Add", mat22_add);
//        livS_mono_add_internal_call("Joy.Mat22::Invert", mat22_invert);
//        livS_mono_add_internal_call("Joy.Mat22::Mul", mat22_mul);
//        livS_mono_add_internal_call("Joy.Mat22::MulVec2", mat22_mul_vec2);
//        livS_mono_add_internal_call("Joy.Mat22::Rotate", mat22_rotate);
//        livS_mono_add_internal_call("Joy.Mat22::Transpose", mat22_transpose);
//
//        livS_mono_add_internal_call("Joy.Mat22::FAbs", mat22f_abs);
//        livS_mono_add_internal_call("Joy.Mat22::FAdd", mat22f_add);
//        livS_mono_add_internal_call("Joy.Mat22::FInvert", mat22f_invert);
//        livS_mono_add_internal_call("Joy.Mat22::FMul", mat22f_mul);
//        livS_mono_add_internal_call("Joy.Mat22::FMulVec2f", mat22f_mul_vec2f);
//        livS_mono_add_internal_call("Joy.Mat22::FRotate", mat22f_rotate);
//        livS_mono_add_internal_call("Joy.Mat22::FTranspose", mat22f_transpose);
//}
