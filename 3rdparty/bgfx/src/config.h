/*
 * Copyright 2011-2021 Branimir Karadzic. All rights reserved.
 * License: https://github.com/bkaradzic/bgfx#license-bsd-2-clause
 */

#ifndef BGFX_CONFIG_H_HEADER_GUARD
#define BGFX_CONFIG_H_HEADER_GUARD

#include <bx/bx.h>

// # Configuration options for bgfx.
//
// Any of `BGFX_CONFIG_*` options that's inside `#ifndef` block can be configured externally
// via compiler options.
//
// When selecting rendering backends select all backends you want to include in the build.

#ifndef BGFX_CONFIG_DEBUG
#	define BGFX_CONFIG_DEBUG 0
#endif // BGFX_CONFIG_DEBUG

#if !defined(BGFX_CONFIG_RENDERER_AGC)        \
 && !defined(BGFX_CONFIG_RENDERER_DIRECT3D9)  \
 && !defined(BGFX_CONFIG_RENDERER_DIRECT3D11) \
 && !defined(BGFX_CONFIG_RENDERER_DIRECT3D12) \
 && !defined(BGFX_CONFIG_RENDERER_GNM)        \
 && !defined(BGFX_CONFIG_RENDERER_METAL)      \
 && !defined(BGFX_CONFIG_RENDERER_NVN)        \
 && !defined(BGFX_CONFIG_RENDERER_OPENGL)     \
 && !defined(BGFX_CONFIG_RENDERER_OPENGLES)   \
 && !defined(BGFX_CONFIG_RENDERER_VULKAN)     \
 && !defined(BGFX_CONFIG_RENDERER_WEBGPU)

#	ifndef BGFX_CONFIG_RENDERER_AGC
#		define BGFX_CONFIG_RENDERER_AGC (0 \
					|| BX_PLATFORM_PS5     \
					? 1 : 0)
#	endif // BGFX_CONFIG_RENDERER_AGC

#	ifndef BGFX_CONFIG_RENDERER_DIRECT3D9
#		define BGFX_CONFIG_RENDERER_DIRECT3D9 (0 \
					|| BX_PLATFORM_WINDOWS       \
					? 1 : 0)
#	endif // BGFX_CONFIG_RENDERER_DIRECT3D9

#	ifndef BGFX_CONFIG_RENDERER_DIRECT3D11
#		define BGFX_CONFIG_RENDERER_DIRECT3D11 (0 \
					|| BX_PLATFORM_WINDOWS        \
					|| BX_PLATFORM_WINRT          \
					|| BX_PLATFORM_XBOXONE        \
					? 1 : 0)
#	endif // BGFX_CONFIG_RENDERER_DIRECT3D11

#	ifndef BGFX_CONFIG_RENDERER_DIRECT3D12
#		define BGFX_CONFIG_RENDERER_DIRECT3D12 (0 \
					|| BX_PLATFORM_WINDOWS        \
					|| BX_PLATFORM_WINRT          \
					|| BX_PLATFORM_XBOXONE        \
					? 1 : 0)
#	endif // BGFX_CONFIG_RENDERER_DIRECT3D12

#	ifndef BGFX_CONFIG_RENDERER_GNM
#		define BGFX_CONFIG_RENDERER_GNM (0 \
					|| BX_PLATFORM_PS4     \
					? 1 : 0)
#	endif // BGFX_CONFIG_RENDERER_GNM

#	ifndef BGFX_CONFIG_RENDERER_METAL
#		define BGFX_CONFIG_RENDERER_METAL (0           \
					|| (BX_PLATFORM_IOS && BX_CPU_ARM) \
					|| (BX_PLATFORM_IOS && BX_CPU_X86) \
					|| (BX_PLATFORM_OSX >= 101100)     \
					? 1 : 0)
#	endif // BGFX_CONFIG_RENDERER_METAL

#	ifndef BGFX_CONFIG_RENDERER_NVN
#		define BGFX_CONFIG_RENDERER_NVN (0 \
					|| BX_PLATFORM_NX      \
					? 1 : 0)
#	endif // BGFX_CONFIG_RENDERER_NVN

#	ifndef BGFX_CONFIG_RENDERER_OPENGL_MIN_VERSION
#		define BGFX_CONFIG_RENDERER_OPENGL_MIN_VERSION 1
#	endif // BGFX_CONFIG_RENDERER_OPENGL_MIN_VERSION

#	ifndef BGFX_CONFIG_RENDERER_OPENGL
#		define BGFX_CONFIG_RENDERER_OPENGL (0 \
					|| BX_PLATFORM_BSD        \
					|| BX_PLATFORM_LINUX      \
					|| BX_PLATFORM_OSX        \
					|| BX_PLATFORM_WINDOWS    \
					? BGFX_CONFIG_RENDERER_OPENGL_MIN_VERSION : 0)
#	endif // BGFX_CONFIG_RENDERER_OPENGL

#	ifndef BGFX_CONFIG_RENDERER_OPENGLES_MIN_VERSION
#		define BGFX_CONFIG_RENDERER_OPENGLES_MIN_VERSION (0 \
					|| BX_PLATFORM_ANDROID                  \
					? 30 : 1)
#	endif // BGFX_CONFIG_RENDERER_OPENGLES_MIN_VERSION

#	ifndef BGFX_CONFIG_RENDERER_OPENGLES
#		define BGFX_CONFIG_RENDERER_OPENGLES (0 \
					|| BX_PLATFORM_ANDROID      \
					|| BX_PLATFORM_EMSCRIPTEN   \
					|| BX_PLATFORM_IOS          \
					|| BX_PLATFORM_RPI          \
					|| BX_PLATFORM_NX           \
					? BGFX_CONFIG_RENDERER_OPENGLES_MIN_VERSION : 0)
#	endif // BGFX_CONFIG_RENDERER_OPENGLES

#	ifndef BGFX_CONFIG_RENDERER_VULKAN
#		define BGFX_CONFIG_RENDERER_VULKAN (0 \
					|| BX_PLATFORM_ANDROID    \
					|| BX_PLATFORM_LINUX      \
					|| BX_PLATFORM_WINDOWS    \
					|| BX_PLATFORM_NX         \
					|| BX_PLATFORM_OSX        \
					? 1 : 0)
#	endif // BGFX_CONFIG_RENDERER_VULKAN

#	ifndef BGFX_CONFIG_RENDERER_WEBGPU
#		define BGFX_CONFIG_RENDERER_WEBGPU 0
#	endif // BGFX_CONFIG_RENDERER_WEBGPU

#else
#	ifndef BGFX_CONFIG_RENDERER_AGC
#		define BGFX_CONFIG_RENDERER_AGC 0
#	endif // BGFX_CONFIG_RENDERER_AGC

#	ifndef BGFX_CONFIG_RENDERER_DIRECT3D9
#		define BGFX_CONFIG_RENDERER_DIRECT3D9 0
#	endif // BGFX_CONFIG_RENDERER_DIRECT3D9

#	ifndef BGFX_CONFIG_RENDERER_DIRECT3D11
#		define BGFX_CONFIG_RENDERER_DIRECT3D11 0
#	endif // BGFX_CONFIG_RENDERER_DIRECT3D11

#	ifndef BGFX_CONFIG_RENDERER_DIRECT3D12
#		define BGFX_CONFIG_RENDERER_DIRECT3D12 0
#	endif // BGFX_CONFIG_RENDERER_DIRECT3D12

#	ifndef BGFX_CONFIG_RENDERER_GNM
#		define BGFX_CONFIG_RENDERER_GNM 0
#	endif // BGFX_CONFIG_RENDERER_GNM

#	ifndef BGFX_CONFIG_RENDERER_METAL
#		define BGFX_CONFIG_RENDERER_METAL 0
#	endif // BGFX_CONFIG_RENDERER_METAL

#	ifndef BGFX_CONFIG_RENDERER_NVN
#		define BGFX_CONFIG_RENDERER_NVN 0
#	endif // BGFX_CONFIG_RENDERER_NVN

#	ifndef BGFX_CONFIG_RENDERER_OPENGL
#		define BGFX_CONFIG_RENDERER_OPENGL 0
#	endif // BGFX_CONFIG_RENDERER_OPENGL

#	ifndef BGFX_CONFIG_RENDERER_OPENGLES
#		define BGFX_CONFIG_RENDERER_OPENGLES 0
#	endif // BGFX_CONFIG_RENDERER_OPENGLES

#	ifndef BGFX_CONFIG_RENDERER_VULKAN
#		define BGFX_CONFIG_RENDERER_VULKAN 0
#	endif // BGFX_CONFIG_RENDERER_VULKAN

#	ifndef BGFX_CONFIG_RENDERER_WEBGPU
#		define BGFX_CONFIG_RENDERER_WEBGPU 0
#	endif // BGFX_CONFIG_RENDERER_VULKAN
#endif // !defined...

#if BGFX_CONFIG_RENDERER_OPENGL && BGFX_CONFIG_RENDERER_OPENGL < 21
#	undef BGFX_CONFIG_RENDERER_OPENGL
#	define BGFX_CONFIG_RENDERER_OPENGL 21
#endif // BGFX_CONFIG_RENDERER_OPENGL && BGFX_CONFIG_RENDERER_OPENGL < 21

#if BGFX_CONFIG_RENDERER_OPENGLES && BGFX_CONFIG_RENDERER_OPENGLES < 20
#	undef BGFX_CONFIG_RENDERER_OPENGLES
#	define BGFX_CONFIG_RENDERER_OPENGLES 20
#endif // BGFX_CONFIG_RENDERER_OPENGLES && BGFX_CONFIG_RENDERER_OPENGLES < 20

#if BGFX_CONFIG_RENDERER_OPENGL && BGFX_CONFIG_RENDERER_OPENGLES
#	error "Can't define both BGFX_CONFIG_RENDERER_OPENGL and BGFX_CONFIG_RENDERER_OPENGLES"
#endif // BGFX_CONFIG_RENDERER_OPENGL && BGFX_CONFIG_RENDERER_OPENGLES

/// Enable use of extensions.
#ifndef BGFX_CONFIG_RENDERER_USE_EXTENSIONS
#	define BGFX_CONFIG_RENDERER_USE_EXTENSIONS 1
#endif // BGFX_CONFIG_RENDERER_USE_EXTENSIONS

/// Enable use of tinystl.
#ifndef BGFX_CONFIG_USE_TINYSTL
#	define BGFX_CONFIG_USE_TINYSTL 1
#endif // BGFX_CONFIG_USE_TINYSTL

/// Enable nVidia PerfHUD integration.
#ifndef BGFX_CONFIG_DEBUG_PERFHUD
#	define BGFX_CONFIG_DEBUG_PERFHUD 0
#endif // BGFX_CONFIG_DEBUG_NVPERFHUD

/// Enable annotation for graphics debuggers.
#ifndef BGFX_CONFIG_DEBUG_ANNOTATION
#	define BGFX_CONFIG_DEBUG_ANNOTATION BGFX_CONFIG_DEBUG
#endif // BGFX_CONFIG_DEBUG_ANNOTATION

/// Enable DX11 object names.
#ifndef BGFX_CONFIG_DEBUG_OBJECT_NAME
#	define BGFX_CONFIG_DEBUG_OBJECT_NAME BGFX_CONFIG_DEBUG_ANNOTATION
#endif // BGFX_CONFIG_DEBUG_OBJECT_NAME

/// Enable uniform debug checks.
#ifndef BGFX_CONFIG_DEBUG_UNIFORM
#	define BGFX_CONFIG_DEBUG_UNIFORM BGFX_CONFIG_DEBUG
#endif // BGFX_CONFIG_DEBUG_UNIFORM

/// Enable occlusion debug checks.
#ifndef BGFX_CONFIG_DEBUG_OCCLUSION
#	define BGFX_CONFIG_DEBUG_OCCLUSION BGFX_CONFIG_DEBUG
#endif // BGFX_CONFIG_DEBUG_OCCLUSION

#ifndef BGFX_CONFIG_MULTITHREADED
#	define BGFX_CONFIG_MULTITHREADED ( (0 == BX_PLATFORM_EMSCRIPTEN) ? 1 : 0)
#endif // BGFX_CONFIG_MULTITHREADED

#ifndef BGFX_CONFIG_MAX_DRAW_CALLS
#	define BGFX_CONFIG_MAX_DRAW_CALLS ( (64<<10)-1)
#endif // BGFX_CONFIG_MAX_DRAW_CALLS

#ifndef BGFX_CONFIG_MAX_BLIT_ITEMS
#	define BGFX_CONFIG_MAX_BLIT_ITEMS (1<<10)
#endif // BGFX_CONFIG_MAX_BLIT_ITEMS

#ifndef BGFX_CONFIG_MAX_MATRIX_CACHE
#	define BGFX_CONFIG_MAX_MATRIX_CACHE (BGFX_CONFIG_MAX_DRAW_CALLS+1)
#endif // BGFX_CONFIG_MAX_MATRIX_CACHE

#ifndef BGFX_CONFIG_MAX_RECT_CACHE
#	define BGFX_CONFIG_MAX_RECT_CACHE (4<<10)
#endif //  BGFX_CONFIG_MAX_RECT_CACHE

#ifndef BGFX_CONFIG_SORT_KEY_NUM_BITS_DEPTH
#	define BGFX_CONFIG_SORT_KEY_NUM_BITS_DEPTH 32
#endif // BGFX_CONFIG_SORT_KEY_NUM_BITS_DEPTH

#ifndef BGFX_CONFIG_SORT_KEY_NUM_BITS_SEQ
#	define BGFX_CONFIG_SORT_KEY_NUM_BITS_SEQ 20
#endif // BGFX_CONFIG_SORT_KEY_NUM_BITS_SEQ

#ifndef BGFX_CONFIG_SORT_KEY_NUM_BITS_PROGRAM
#	define BGFX_CONFIG_SORT_KEY_NUM_BITS_PROGRAM 9
#endif // BGFX_CONFIG_SORT_KEY_NUM_BITS_PROGRAM

// Cannot be configured via compiler options.
#define BGFX_CONFIG_MAX_PROGRAMS (1<<BGFX_CONFIG_SORT_KEY_NUM_BITS_PROGRAM)
BX_STATIC_ASSERT(bx::isPowerOf2(BGFX_CONFIG_MAX_PROGRAMS), "BGFX_CONFIG_MAX_PROGRAMS must be power of 2.");

#ifndef BGFX_CONFIG_MAX_VIEWS
#	define BGFX_CONFIG_MAX_VIEWS 256
#endif // BGFX_CONFIG_MAX_VIEWS
BX_STATIC_ASSERT(bx::isPowerOf2(BGFX_CONFIG_MAX_VIEWS), "BGFX_CONFIG_MAX_VIEWS must be power of 2.");

#define BGFX_CONFIG_MAX_VIEW_NAME_RESERVED 6

#ifndef BGFX_CONFIG_MAX_VIEW_NAME
#	define BGFX_CONFIG_MAX_VIEW_NAME 256
#endif // BGFX_CONFIG_MAX_VIEW_NAME

#ifndef BGFX_CONFIG_MAX_VERTEX_LAYOUTS
#	define BGFX_CONFIG_MAX_VERTEX_LAYOUTS 64
#endif // BGFX_CONFIG_MAX_VERTEX_LAYOUTS

#ifndef BGFX_CONFIG_MAX_INDEX_BUFFERS
#	define BGFX_CONFIG_MAX_INDEX_BUFFERS (4<<10)
#endif // BGFX_CONFIG_MAX_INDEX_BUFFERS

#ifndef BGFX_CONFIG_MAX_VERTEX_BUFFERS
#	define BGFX_CONFIG_MAX_VERTEX_BUFFERS (4<<10)
#endif // BGFX_CONFIG_MAX_VERTEX_BUFFERS

#ifndef BGFX_CONFIG_MAX_VERTEX_STREAMS
#	define BGFX_CONFIG_MAX_VERTEX_STREAMS 4
#endif // BGFX_CONFIG_MAX_VERTEX_STREAMS

#ifndef BGFX_CONFIG_MAX_DYNAMIC_INDEX_BUFFERS
#	define BGFX_CONFIG_MAX_DYNAMIC_INDEX_BUFFERS (4<<10)
#endif // BGFX_CONFIG_MAX_DYNAMIC_INDEX_BUFFERS

#ifndef BGFX_CONFIG_MAX_DYNAMIC_VERTEX_BUFFERS
#	define BGFX_CONFIG_MAX_DYNAMIC_VERTEX_BUFFERS (4<<10)
#endif // BGFX_CONFIG_MAX_DYNAMIC_VERTEX_BUFFERS

#ifndef BGFX_CONFIG_DYNAMIC_INDEX_BUFFER_SIZE
#	define BGFX_CONFIG_DYNAMIC_INDEX_BUFFER_SIZE (1<<20)
#endif // BGFX_CONFIG_DYNAMIC_INDEX_BUFFER_SIZE

#ifndef BGFX_CONFIG_DYNAMIC_VERTEX_BUFFER_SIZE
#	define BGFX_CONFIG_DYNAMIC_VERTEX_BUFFER_SIZE (3<<20)
#endif // BGFX_CONFIG_DYNAMIC_VERTEX_BUFFER_SIZE

#ifndef BGFX_CONFIG_MAX_SHADERS
#	define BGFX_CONFIG_MAX_SHADERS 512
#endif // BGFX_CONFIG_MAX_FRAGMENT_SHADERS

#ifndef BGFX_CONFIG_MAX_TEXTURES
#	define BGFX_CONFIG_MAX_TEXTURES (4<<10)
#endif // BGFX_CONFIG_MAX_TEXTURES

#ifndef BGFX_CONFIG_MAX_TEXTURE_SAMPLERS
#	define BGFX_CONFIG_MAX_TEXTURE_SAMPLERS 16
#endif // BGFX_CONFIG_MAX_TEXTURE_SAMPLERS

#ifndef BGFX_CONFIG_MAX_FRAME_BUFFERS
#	define BGFX_CONFIG_MAX_FRAME_BUFFERS 128
#endif // BGFX_CONFIG_MAX_FRAME_BUFFERS

#ifndef BGFX_CONFIG_MAX_FRAME_BUFFER_ATTACHMENTS
#	define BGFX_CONFIG_MAX_FRAME_BUFFER_ATTACHMENTS 8
#endif // BGFX_CONFIG_MAX_FRAME_BUFFER_ATTACHMENTS

#ifndef BGFX_CONFIG_MAX_UNIFORMS
#	define BGFX_CONFIG_MAX_UNIFORMS 512
#endif // BGFX_CONFIG_MAX_UNIFORMS

#ifndef BGFX_CONFIG_MAX_OCCLUSION_QUERIES
#	define BGFX_CONFIG_MAX_OCCLUSION_QUERIES 256
#endif // BGFX_CONFIG_MAX_OCCLUSION_QUERIES

#ifndef BGFX_CONFIG_MIN_RESOURCE_COMMAND_BUFFER_SIZE
#	define BGFX_CONFIG_MIN_RESOURCE_COMMAND_BUFFER_SIZE (64<<10)
#endif // BGFX_CONFIG_MIN_RESOURCE_COMMAND_BUFFER_SIZE

#ifndef BGFX_CONFIG_TRANSIENT_VERTEX_BUFFER_SIZE
#	define BGFX_CONFIG_TRANSIENT_VERTEX_BUFFER_SIZE (6<<20)
#endif // BGFX_CONFIG_TRANSIENT_VERTEX_BUFFER_SIZE

#ifndef BGFX_CONFIG_TRANSIENT_INDEX_BUFFER_SIZE
#	define BGFX_CONFIG_TRANSIENT_INDEX_BUFFER_SIZE (2<<20)
#endif // BGFX_CONFIG_TRANSIENT_INDEX_BUFFER_SIZE

#ifndef BGFX_CONFIG_MAX_INSTANCE_DATA_COUNT
#	define BGFX_CONFIG_MAX_INSTANCE_DATA_COUNT 5
#endif // BGFX_CONFIG_MAX_INSTANCE_DATA_COUNT

#ifndef BGFX_CONFIG_MAX_COLOR_PALETTE
#	define BGFX_CONFIG_MAX_COLOR_PALETTE 16
#endif // BGFX_CONFIG_MAX_COLOR_PALETTE

#define BGFX_CONFIG_DRAW_INDIRECT_STRIDE 32

#ifndef BGFX_CONFIG_PROFILER
#	define BGFX_CONFIG_PROFILER 0
#endif // BGFX_CONFIG_PROFILER

#ifndef BGFX_CONFIG_RENDERDOC_LOG_FILEPATH
#	define BGFX_CONFIG_RENDERDOC_LOG_FILEPATH "temp/bgfx"
#endif // BGFX_CONFIG_RENDERDOC_LOG_FILEPATH

#ifndef BGFX_CONFIG_RENDERDOC_CAPTURE_KEYS
#	define BGFX_CONFIG_RENDERDOC_CAPTURE_KEYS { eRENDERDOC_Key_F11 }
#endif // BGFX_CONFIG_RENDERDOC_CAPTURE_KEYS

#ifndef BGFX_CONFIG_API_SEMAPHORE_TIMEOUT
#	define BGFX_CONFIG_API_SEMAPHORE_TIMEOUT (5000)
#endif // BGFX_CONFIG_API_SEMAPHORE_TIMEOUT

#ifndef BGFX_CONFIG_MIP_LOD_BIAS
#	define BGFX_CONFIG_MIP_LOD_BIAS 0
#endif // BGFX_CONFIG_MIP_LOD_BIAS

#ifndef BGFX_CONFIG_DEFAULT_MAX_ENCODERS
#	define BGFX_CONFIG_DEFAULT_MAX_ENCODERS ( (0 != BGFX_CONFIG_MULTITHREADED) ? 8 : 1)
#endif // BGFX_CONFIG_DEFAULT_MAX_ENCODERS

#ifndef BGFX_CONFIG_MAX_BACK_BUFFERS
#	define BGFX_CONFIG_MAX_BACK_BUFFERS 4
#endif // BGFX_CONFIG_MAX_BACK_BUFFERS

#ifndef BGFX_CONFIG_MAX_FRAME_LATENCY
#	define BGFX_CONFIG_MAX_FRAME_LATENCY 3
#endif // BGFX_CONFIG_MAX_FRAME_LATENCY

#ifndef BGFX_CONFIG_PREFER_DISCRETE_GPU
// On laptops with integrated and discrete GPU, prefer selection of discrete GPU.
// nVidia and AMD, on Windows only.
#	define BGFX_CONFIG_PREFER_DISCRETE_GPU BX_PLATFORM_WINDOWS
#endif // BGFX_CONFIG_PREFER_DISCRETE_GPU

#ifndef BGFX_CONFIG_MAX_SCREENSHOTS
#	define BGFX_CONFIG_MAX_SCREENSHOTS 4
#endif // BGFX_CONFIG_MAX_SCREENSHOTS

#ifndef BGFX_CONFIG_ENCODER_API_ONLY
#	define BGFX_CONFIG_ENCODER_API_ONLY 0
#endif // BGFX_CONFIG_ENCODER_API_ONLY

#endif // BGFX_CONFIG_H_HEADER_GUARD
