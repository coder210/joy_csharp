//#include "../mono.h"
#include "csclib.h"
//
//static int
//set_window_icon(SDL_Window* window, const char* bmp)
//{
//	SDL_Surface* icon;
//	Uint32 key;
//	icon = SDL_LoadBMP(bmp);
//	if (icon) {
//		key = SDL_MapSurfaceRGB(icon, 255, 255, 255);
//		SDL_SetSurfaceColorKey(icon, true, key);
//		SDL_SetWindowIcon(window, icon);
//		SDL_DestroySurface(icon);
//		return 0;
//	}
//	else {
//		return 1;
//	}
//}
//
//static SDL_AudioDeviceID open_default_audio_device()
//{
//	SDL_AudioDeviceID audio_device;
//	audio_device = SDL_OpenAudioDevice(SDL_AUDIO_DEVICE_DEFAULT_PLAYBACK, NULL);
//	return audio_device;
//}
//
//
//static int put_audio_stream_data(SDL_AudioStream* stream, Uint8* data, Uint32 data_len)
//{
//	if (SDL_GetAudioStreamQueued(stream) < data_len) {
//		SDL_PutAudioStreamData(stream, data, data_len);
//		return 0;
//	}
//	return 1;
//}
//
//
//static SDL_Texture*
//create_texture_from_surface(SDL_Renderer* renderer, const char* file)
//{
//	SDL_Surface* surface;
//	SDL_Texture* texture;
//	surface = SDL_LoadBMP(file);
//	texture = SDL_CreateTextureFromSurface(renderer, surface);
//	SDL_DestroySurface(surface);
//	return texture;
//}
//
//static SDL_GPUShader*
//create_vertex_shader(SDL_GPUDevice* device, const char* filename, const char* entrypoint)
//{
//	SDL_GPUShader* shader;
//	Uint8* file_data;
//	size_t data_size;
//	SDL_GPUShaderCreateInfo ci;
//	file_data = (Uint8*)SDL_LoadFile(filename, &data_size);
//	if (file_data) {
//		ci.code = file_data;
//		ci.code_size = data_size;
//		ci.entrypoint = entrypoint;
//		ci.format = SDL_GPU_SHADERFORMAT_SPIRV;
//		ci.num_samplers = 0;
//		ci.num_storage_buffers = 0;
//		ci.num_storage_textures = 0;
//		ci.num_uniform_buffers = 0;
//		ci.stage = SDL_GPU_SHADERSTAGE_VERTEX;
//		shader = SDL_CreateGPUShader(device, &ci);
//	}
//	else {
//		shader = NULL;
//	}
//
//	return shader;
//
//}
//
//static SDL_GPUShader*
//create_fragment_shader(SDL_GPUDevice* device, const char* filename, const char* entrypoint)
//{
//	SDL_GPUShader* shader;
//	Uint8* file_data;
//	size_t data_size;
//	SDL_GPUShaderCreateInfo ci;
//	file_data = (Uint8*)SDL_LoadFile(filename, &data_size);
//	if (file_data) {
//		ci.code = file_data;
//		ci.code_size = data_size;
//		ci.entrypoint = entrypoint;
//		ci.format = SDL_GPU_SHADERFORMAT_SPIRV;
//		ci.num_samplers = 1;
//		ci.num_storage_buffers = 0;
//		ci.num_storage_textures = 0;
//		ci.num_uniform_buffers = 0;
//		ci.stage = SDL_GPU_SHADERSTAGE_FRAGMENT;
//		shader = SDL_CreateGPUShader(device, &ci);
//	}
//	else {
//		shader = NULL;
//	}
//
//	return shader;
//}
//
//
//
//static SDL_GPUGraphicsPipeline*
//create_graphics_pipeline(SDL_GPUDevice* device, SDL_Window* window, SDL_GPUShader* vertex, SDL_GPUShader* fragment)
//{
//	SDL_GPUGraphicsPipelineCreateInfo ci;
//	SDL_GPUVertexAttribute attributes[3];
//	SDL_GPUVertexBufferDescription vertex_buffer_desc;
//	SDL_GPUColorTargetDescription desc;
//	SDL_GPUGraphicsPipeline* pipeline;
//
//	memset(&ci, 0, sizeof(SDL_GPUGraphicsPipelineCreateInfo));
//
//
//	/*position attribute*/
//	attributes[0].location = 0;
//	attributes[0].buffer_slot = 0;
//	attributes[0].format = SDL_GPU_VERTEXELEMENTFORMAT_FLOAT2;
//	attributes[0].offset = 0;
//
//	/*color attribute*/
//	attributes[1].location = 1;
//	attributes[1].buffer_slot = 0;
//	attributes[1].format = SDL_GPU_VERTEXELEMENTFORMAT_FLOAT3;
//	attributes[1].offset = sizeof(float) * 2;
//
//	/*uv attribute*/
//	attributes[2].location = 2;
//	attributes[2].buffer_slot = 0;
//	attributes[2].format = SDL_GPU_VERTEXELEMENTFORMAT_FLOAT2;
//	attributes[2].offset = sizeof(float) * 5;
//
//	ci.vertex_input_state.vertex_attributes = attributes;
//	ci.vertex_input_state.num_vertex_attributes = 3;
//
//	vertex_buffer_desc.input_rate = SDL_GPU_VERTEXINPUTRATE_VERTEX;
//	vertex_buffer_desc.instance_step_rate = 0;
//	vertex_buffer_desc.slot = 0;
//	vertex_buffer_desc.pitch = sizeof(float) * 7;
//
//	ci.vertex_input_state.num_vertex_buffers = 1;
//	ci.vertex_input_state.vertex_buffer_descriptions = &vertex_buffer_desc;
//
//	ci.primitive_type = SDL_GPU_PRIMITIVETYPE_TRIANGLELIST;
//	ci.vertex_shader = vertex;
//	ci.fragment_shader = fragment;
//
//	ci.rasterizer_state.cull_mode = SDL_GPU_CULLMODE_NONE;
//	ci.rasterizer_state.fill_mode = SDL_GPU_FILLMODE_FILL;
//
//	ci.multisample_state.enable_mask = false;
//	ci.multisample_state.sample_count = SDL_GPU_SAMPLECOUNT_1;
//
//	ci.target_info.num_color_targets = 1;
//	ci.target_info.has_depth_stencil_target = false;
//
//	desc.blend_state.alpha_blend_op = SDL_GPU_BLENDOP_ADD;
//	desc.blend_state.color_blend_op = SDL_GPU_BLENDOP_ADD;
//	desc.blend_state.color_write_mask =
//		SDL_GPU_COLORCOMPONENT_A | SDL_GPU_COLORCOMPONENT_R |
//		SDL_GPU_COLORCOMPONENT_G | SDL_GPU_COLORCOMPONENT_B;
//	desc.blend_state.src_alpha_blendfactor = SDL_GPU_BLENDFACTOR_ONE;
//	desc.blend_state.src_color_blendfactor = SDL_GPU_BLENDFACTOR_ONE;
//	desc.blend_state.dst_alpha_blendfactor = SDL_GPU_BLENDFACTOR_ZERO;
//	desc.blend_state.dst_color_blendfactor = SDL_GPU_BLENDFACTOR_ZERO;
//	desc.blend_state.enable_blend = true;
//	desc.blend_state.enable_color_write_mask = false;
//	desc.format = SDL_GetGPUSwapchainTextureFormat(device, window);
//
//	ci.target_info.color_target_descriptions = &desc;
//
//	pipeline = SDL_CreateGPUGraphicsPipeline(device, &ci);
//
//	return pipeline;
//}
//
//
//typedef struct vertex {
//	float x, y;
//	float r, g, b;
//	float u, v;
//}vertex_p;
//
//
//static SDL_GPUBuffer* create_and_upload_vertex_data(SDL_GPUDevice* device, vertex_p* vertices, int vertices_len)
//{
//	SDL_GPUBuffer* vertex_buffer;
//	SDL_GPUTransferBufferCreateInfo transfer_buffer_ci;
//	SDL_GPUTransferBuffer* transfer_buffer;
//	void* ptr;
//	SDL_GPUBufferCreateInfo gpu_buffer_ci;
//	SDL_GPUCommandBuffer* cmd;
//	SDL_GPUCopyPass* copy_pass;
//	SDL_GPUTransferBufferLocation location;
//	SDL_GPUBufferRegion region;
//
//	transfer_buffer_ci.size = sizeof(vertices);
//	transfer_buffer_ci.usage = SDL_GPU_TRANSFERBUFFERUSAGE_UPLOAD;
//
//	transfer_buffer = SDL_CreateGPUTransferBuffer(device, &transfer_buffer_ci);
//	ptr = SDL_MapGPUTransferBuffer(device, transfer_buffer, false);
//	memcpy(ptr, &vertices, sizeof(vertices));
//	SDL_UnmapGPUTransferBuffer(device, transfer_buffer);
//
//	gpu_buffer_ci.size = sizeof(vertices);
//	gpu_buffer_ci.usage = SDL_GPU_BUFFERUSAGE_VERTEX;
//
//	vertex_buffer = SDL_CreateGPUBuffer(device, &gpu_buffer_ci);
//
//	cmd = SDL_AcquireGPUCommandBuffer(device);
//	copy_pass = SDL_BeginGPUCopyPass(cmd);
//	location.offset = 0;
//	location.transfer_buffer = transfer_buffer;
//	region.buffer = vertex_buffer;
//	region.offset = 0;
//	region.size = sizeof(vertices);
//	SDL_UploadToGPUBuffer(copy_pass, &location, &region, false);
//	SDL_EndGPUCopyPass(copy_pass);
//	SDL_SubmitGPUCommandBuffer(cmd);
//	SDL_ReleaseGPUTransferBuffer(device, transfer_buffer);
//	SDL_free(vertices);
//	return vertex_buffer;
//}
//
//
//static SDL_GPUBuffer*
//create_and_upload_indices_data(SDL_GPUDevice* device, uint32_t* indices, int indices_len)
//{
//	SDL_GPUTransferBufferCreateInfo transfer_buffer_ci;
//	SDL_GPUTransferBuffer* transfer_buffer;
//	void* ptr;
//	SDL_GPUBufferCreateInfo gpu_buffer_ci;
//	SDL_GPUBuffer* indices_buffer;
//	SDL_GPUCommandBuffer* cmd;
//	SDL_GPUCopyPass* copy_pass;
//	SDL_GPUTransferBufferLocation location;
//	SDL_GPUBufferRegion region;
//
//	transfer_buffer_ci.size = sizeof(indices);
//	transfer_buffer_ci.usage = SDL_GPU_TRANSFERBUFFERUSAGE_UPLOAD;
//
//	transfer_buffer = SDL_CreateGPUTransferBuffer(device, &transfer_buffer_ci);
//	ptr = SDL_MapGPUTransferBuffer(device, transfer_buffer, false);
//	memcpy(ptr, &indices, sizeof(indices));
//	SDL_UnmapGPUTransferBuffer(device, transfer_buffer);
//
//	gpu_buffer_ci.size = sizeof(indices);
//	gpu_buffer_ci.usage = SDL_GPU_BUFFERUSAGE_INDEX;
//
//	indices_buffer = SDL_CreateGPUBuffer(device, &gpu_buffer_ci);
//
//	cmd = SDL_AcquireGPUCommandBuffer(device);
//	copy_pass = SDL_BeginGPUCopyPass(cmd);
//	location.offset = 0;
//	location.transfer_buffer = transfer_buffer;
//	region.buffer = indices_buffer;
//	region.offset = 0;
//	region.size = sizeof(indices);
//	SDL_UploadToGPUBuffer(copy_pass, &location, &region, false);
//	SDL_EndGPUCopyPass(copy_pass);
//
//	SDL_SubmitGPUCommandBuffer(cmd);
//
//	SDL_ReleaseGPUTransferBuffer(device, transfer_buffer);
//
//	SDL_free(indices);
//
//	return indices_buffer;
//}


//static SDL_GPUTexture*
//create_gpu_texture(SDL_GPUDevice* device, const char* filename)
//{
//	int w, h;
//	unsigned char* image_data;
//	SDL_GPUTransferBufferCreateInfo transfer_buffer_ci;
//	SDL_GPUTransferBuffer* transfer_buffer;
//	void* ptr;
//	SDL_GPUTextureCreateInfo texture_ci;
//	SDL_GPUTexture* texture;
//	SDL_GPUCommandBuffer* cmd;
//	SDL_GPUCopyPass* copy_pass;
//	SDL_GPUTextureTransferInfo transfer_info;
//	SDL_GPUTextureRegion region;
//
//	stbi_set_flip_vertically_on_load(true);
//
//	image_data = stbi_load(filename, &w, &h, NULL, STBI_rgb_alpha);
//
//	transfer_buffer_ci.size = 4 * w * h;
//	transfer_buffer_ci.usage = SDL_GPU_TRANSFERBUFFERUSAGE_UPLOAD;
//
//	transfer_buffer = SDL_CreateGPUTransferBuffer(device, &transfer_buffer_ci);
//	ptr = SDL_MapGPUTransferBuffer(device, transfer_buffer, false);
//	memcpy(ptr, image_data, transfer_buffer_ci.size);
//	SDL_UnmapGPUTransferBuffer(device, transfer_buffer);
//
//	texture_ci.format = SDL_GPU_TEXTUREFORMAT_R8G8B8A8_UNORM;
//	texture_ci.height = h;
//	texture_ci.width = w;
//	texture_ci.layer_count_or_depth = 1;
//	texture_ci.num_levels = 1;
//	texture_ci.sample_count = SDL_GPU_SAMPLECOUNT_1;
//	texture_ci.type = SDL_GPU_TEXTURETYPE_2D;
//	texture_ci.usage = SDL_GPU_TEXTUREUSAGE_SAMPLER;
//
//	texture = SDL_CreateGPUTexture(device, &texture_ci);
//
//	cmd = SDL_AcquireGPUCommandBuffer(device);
//	copy_pass = SDL_BeginGPUCopyPass(cmd);
//
//	transfer_info.offset = 0;
//	transfer_info.pixels_per_row = w;
//	transfer_info.rows_per_layer = h;
//	transfer_info.transfer_buffer = transfer_buffer;
//
//	region.w = w;
//	region.h = h;
//	region.x = 0;
//	region.y = 0;
//	region.layer = 0;
//	region.mip_level = 0;
//	region.z = 0;
//	region.d = 1;
//	region.texture = texture;
//
//	SDL_UploadToGPUTexture(copy_pass, &transfer_info, &region, false);
//	SDL_EndGPUCopyPass(copy_pass);
//	SDL_SubmitGPUCommandBuffer(cmd);
//	SDL_ReleaseGPUTransferBuffer(device, transfer_buffer);
//	stbi_image_free(image_data);
//
//	return texture;
//}

//
//
//static SDL_GPUSampler*
//create_gpu_sampler(SDL_GPUDevice* device)
//{
//	SDL_GPUSampler* sampler;
//	SDL_GPUSamplerCreateInfo ci;
//
//	ci.address_mode_u = SDL_GPU_SAMPLERADDRESSMODE_CLAMP_TO_EDGE;
//	ci.address_mode_v = SDL_GPU_SAMPLERADDRESSMODE_CLAMP_TO_EDGE;
//	ci.address_mode_w = SDL_GPU_SAMPLERADDRESSMODE_CLAMP_TO_EDGE;
//	ci.enable_anisotropy = false;
//	ci.compare_op = SDL_GPU_COMPAREOP_ALWAYS;
//	ci.enable_compare = false;
//	ci.mag_filter = SDL_GPU_FILTER_LINEAR;
//	ci.min_filter = SDL_GPU_FILTER_LINEAR;
//	ci.max_lod = 1.0;
//	ci.min_lod = 1.0;
//	ci.mip_lod_bias = 0.0;
//	ci.mipmap_mode = SDL_GPU_SAMPLERMIPMAPMODE_LINEAR;
//	sampler = SDL_CreateGPUSampler(device, &ci);
//
//	return sampler;
//}
//
//
//static int
//gpu_update(SDL_GPUDevice* device, SDL_Window* window, SDL_GPUGraphicsPipeline* pipeline, SDL_GPUBuffer* vertex_buffer, SDL_GPUBuffer* indices_buffer, SDL_GPUTexture* texture, SDL_GPUSampler* sampler)
//{
//	SDL_GPUCommandBuffer* cmd;
//	SDL_GPUTexture* swapchain_texture;
//	Uint32 width, height;
//	SDL_GPUColorTargetInfo color_ti;
//	SDL_GPURenderPass* render_pass;
//	SDL_GPUBufferBinding indices_binding;
//	SDL_GPUBufferBinding vertex_binding;
//	SDL_GPUTextureSamplerBinding sampler_binding;
//	int window_width, window_height;
//	SDL_GPUViewport viewport;
//	bool is_minimized;
//
//
//	is_minimized = SDL_GetWindowFlags(window) & SDL_WINDOW_MINIMIZED;
//	if (is_minimized) {
//		return 0;
//	}
//
//	cmd = SDL_AcquireGPUCommandBuffer(device);
//	SDL_WaitAndAcquireGPUSwapchainTexture(cmd, window,
//		&swapchain_texture, &width, &height);
//	if (!swapchain_texture)
//		return 0;
//
//	memset(&color_ti, 0, sizeof(color_ti));
//	color_ti.clear_color.r = 0.1f;
//	color_ti.clear_color.g = 0.1f;
//	color_ti.clear_color.b = 0.1f;
//	color_ti.clear_color.a = 1.0f;
//	color_ti.load_op = SDL_GPU_LOADOP_CLEAR;
//	color_ti.mip_level = 0;
//	color_ti.store_op = SDL_GPU_STOREOP_STORE;
//	color_ti.texture = swapchain_texture;
//	color_ti.cycle = true;
//	color_ti.layer_or_depth_plane = 0;
//	color_ti.cycle_resolve_texture = false;
//	render_pass = SDL_BeginGPURenderPass(cmd, &color_ti, 1, NULL);
//	SDL_BindGPUGraphicsPipeline(render_pass, pipeline);
//
//	vertex_binding.buffer = vertex_buffer;
//	vertex_binding.offset = 0;
//	SDL_BindGPUVertexBuffers(render_pass, 0, &vertex_binding, 1);
//
//	indices_binding.buffer = indices_buffer;
//	indices_binding.offset = 0;
//	SDL_BindGPUIndexBuffer(render_pass, &indices_binding,
//		SDL_GPU_INDEXELEMENTSIZE_32BIT);
//
//	sampler_binding.texture = texture;
//	sampler_binding.sampler = sampler;
//	SDL_BindGPUFragmentSamplers(render_pass, 0, &sampler_binding, 1);
//
//	SDL_GetWindowSize(window, &window_width, &window_height);
//
//	viewport.x = 0;
//	viewport.y = 0;
//	viewport.w = window_width * 1.0f;
//	viewport.h = window_height * 1.0f;
//	viewport.min_depth = 0;
//	viewport.max_depth = 1;
//	SDL_SetGPUViewport(render_pass, &viewport);
//	SDL_DrawGPUIndexedPrimitives(render_pass, 6, 1, 0, 0, 0);
//	SDL_EndGPURenderPass(render_pass);
//	SDL_SubmitGPUCommandBuffer(cmd);
//
//	return 0;
//}
//
//
//static SDL_Environment* create_environment(bool populated)
//{
//	return SDL_CreateEnvironment(populated);
//}
//
//static MonoString*
//get_environment_variable(SDL_Environment* env, MonoString* name)
//{
//	char* cstr_name;
//	const char* cstr_value;
//	cstr_name = livS_mono_string_to_utf8(name);
//	cstr_value = SDL_GetEnvironmentVariable(env, cstr_name);
//	return livS_mono_string_new(livS_mono_domain_get(), cstr_value);
//}
//
//static bool
//set_environment_variable(SDL_Environment* env, MonoString* name, MonoString* value, bool overwrite)
//{
//	bool result;
//	char* cstr_name, * cstr_value;
//	cstr_name = livS_mono_string_to_utf8(name);
//	cstr_value = livS_mono_string_to_utf8(value);
//	result = SDL_SetEnvironmentVariable(env, cstr_name, cstr_value, overwrite);
//	return result;
//}
//
//
//static uint32_t get_event_type(SDL_Event* event)
//{
//	return event->type;
//}
//
//static int get_event_scancode(SDL_Event* event)
//{
//	return event->key.scancode;
//}
//
//typedef union Persion
//{
//	//MonoString *name;
//	char name[512];
//	int age;
//	float score;
//}Persion;
//
//static Persion get_person_name()
//{
//	Persion person = { 0 };
//	SDL_strlcpy(person.name, "nczx", 511);
//	//person.name = livS_mono_string_new(livS_mono_domain_get(), "nczx");
//	return person;
//}
//
//static Persion get_person_age()
//{
//	Persion person = { 0 };
//	person.age = 100;
//	return person;
//}
//
//static Persion get_person_score()
//{
//	Persion person = { 0 };
//	person.score = 72.5f;
//	return person;
//}
//
//static bool
//create_Window_and_renderer(MonoString* title, int width, int height, SDL_WindowFlags window_flags, SDL_Window** window, SDL_Renderer** renderer)
//{
//	bool ok;
//	char* cstr_title;
//	cstr_title = livS_mono_string_to_utf8(title);
//	ok = SDL_CreateWindowAndRenderer(cstr_title, width, height, window_flags, window, renderer);
//	return ok;
//}
//
//static int thread_main(void* arg)
//{
//	MonoObject* delegate;
//	MonoObject* result;
//	MonoObject* exc;
//
//	//uint32_t gchandle = (uint32_t)(uintptr_t)arg;
//
//
//	//delegate = livS_mono_gchandle_get_target(gchandle);
//
//	//result = livS_mono_runtime_delegate_invoke(delegate, NULL, &exc);
//	//// 6. 检查异常
//	//if (exc) {
//	//	// 处理异常 - 打印堆栈跟踪等
//	//	livS_mono_print_unhandled_exception(exc);
//	//}
//	//// 7. 释放GC句柄
//	//livS_mono_gchandle_free(gchandle);
//
//	delegate = (MonoObject*)arg;
//	//MonoDomain *domain = livS_mono_object_get_domain(delegate);
//	//livS_mono_runtime_delegate_invoke(delegate, NULL, &exc);
//	return 0;
//}
//
//static SDL_Thread*
//create_thread(MonoObject* delegate, MonoString* name)
//{
//	//uint32_t gchandle = livS_mono_gchandle_new(delegate, 0); // 0 = 普通引用
//
//	SDL_Thread* thread;
//	const char* cstr_name;
//	cstr_name = livS_mono_string_to_utf8(name);
//
//	MonoDomain* domain = livS_mono_domain_get();
//	//MonoThread* thread = livS_mono_thread_attach(domain);
//	//livS_mono_runtime_delegate_invoke(delegate, NULL, NULL);
//	thread = SDL_CreateThread(thread_main, cstr_name, delegate);
//	//livS_mono_free(name);
//	return thread;
//}
//
//
//void csopen_sdl()
//{
//	livS_mono_add_internal_call("Joy.SDL::SetAppMetadata", SDL_SetAppMetadata);
//	livS_mono_add_internal_call("Joy.SDL::Init", SDL_Init);
//	livS_mono_add_internal_call("Joy.SDL::Quit", SDL_Quit);
//	livS_mono_add_internal_call("Joy.SDL::GetVersion", SDL_GetVersion);
//	livS_mono_add_internal_call("Joy.SDL::Log", SDL_Log);
//	livS_mono_add_internal_call("Joy.SDL::LogError", SDL_LogError);
//	livS_mono_add_internal_call("Joy.SDL::Delay", SDL_Delay);
//	livS_mono_add_internal_call("Joy.SDL::GetCurrentDisplayMode", SDL_GetCurrentDisplayMode);
//	livS_mono_add_internal_call("Joy.SDL::CreateWindow", SDL_CreateWindow);
//	livS_mono_add_internal_call("Joy.SDL::GetWindowSize", SDL_GetWindowSize);
//	livS_mono_add_internal_call("Joy.SDL::DestroyWindow", SDL_DestroyWindow);
//	livS_mono_add_internal_call("Joy.SDL::CreateWindowAndRenderer", create_Window_and_renderer);
//	livS_mono_add_internal_call("Joy.SDL::SetWindowIcon", set_window_icon);
//	livS_mono_add_internal_call("Joy.SDL::SetWindowFullscreen", SDL_SetWindowFullscreen);
//	livS_mono_add_internal_call("Joy.SDL::CreateRenderer", SDL_CreateRenderer);
//	livS_mono_add_internal_call("Joy.SDL::DestroyRenderer", SDL_DestroyRenderer);
//	livS_mono_add_internal_call("Joy.SDL::SetRenderVSync", SDL_SetRenderVSync);
//	livS_mono_add_internal_call("Joy.SDL::RenderClear", SDL_RenderClear);
//	livS_mono_add_internal_call("Joy.SDL::RenderPresent", SDL_RenderPresent);
//	livS_mono_add_internal_call("Joy.SDL::SetRenderScale", SDL_SetRenderScale);
//	livS_mono_add_internal_call("Joy.SDL::RenderDebugText", SDL_RenderDebugText);
//	livS_mono_add_internal_call("Joy.SDL::SetRenderDrawColor", SDL_SetRenderDrawColor);
//	livS_mono_add_internal_call("Joy.SDL::RenderPoint", SDL_RenderPoint);
//	livS_mono_add_internal_call("Joy.SDL::RenderLine", SDL_RenderLine);
//	livS_mono_add_internal_call("Joy.SDL::RenderRect", SDL_RenderRect);
//	livS_mono_add_internal_call("Joy.SDL::RenderFillRect", SDL_RenderFillRect);
//	//livS_mono_add_internal_call("Joy.SDL::OpenFont", open_font);
//	//livS_mono_add_internal_call("Joy.SDL::CloseFont", close_font);
//	livS_mono_add_internal_call("Joy.SDL::LoadWAV", SDL_LoadWAV);
//	livS_mono_add_internal_call("Joy.SDL::CreateAudioStream", SDL_CreateAudioStream);
//	livS_mono_add_internal_call("Joy.SDL::OpenDefaultAudioDevice", open_default_audio_device);
//	livS_mono_add_internal_call("Joy.SDL::PauseAudioDevice", SDL_PauseAudioDevice);
//	livS_mono_add_internal_call("Joy.SDL::ResumeAudioDevice", SDL_ResumeAudioDevice);
//	livS_mono_add_internal_call("Joy.SDL::BindAudioStream", SDL_BindAudioStream);
//	livS_mono_add_internal_call("Joy.SDL::GetAudioDeviceGain", SDL_GetAudioDeviceGain);
//	livS_mono_add_internal_call("Joy.SDL::SetAudioDeviceGain", SDL_SetAudioDeviceGain);
//	livS_mono_add_internal_call("Joy.SDL::CloseAudioDevice", SDL_CloseAudioDevice);
//	livS_mono_add_internal_call("Joy.SDL::DestroyAudioStream", SDL_DestroyAudioStream);
//	livS_mono_add_internal_call("Joy.SDL::PutAudioStreamData", put_audio_stream_data);
//	livS_mono_add_internal_call("Joy.SDL::GetTicks", SDL_GetTicks);
//	livS_mono_add_internal_call("Joy.SDL::CreateTextureFromSurface", create_texture_from_surface);
//	livS_mono_add_internal_call("Joy.SDL::GetTextureSize", SDL_GetTextureSize);
//	livS_mono_add_internal_call("Joy.SDL::RenderTextureRotated", SDL_RenderTextureRotated);
//	livS_mono_add_internal_call("Joy.SDL::DestroyTexture", SDL_DestroyTexture);
//	livS_mono_add_internal_call("Joy.SDL::LoadFile", SDL_LoadFile);
//	livS_mono_add_internal_call("Joy.SDL::PollEvent", SDL_PollEvent);
//	livS_mono_add_internal_call("Joy.SDL::GetNumGPUDrivers", SDL_GetNumGPUDrivers);
//	livS_mono_add_internal_call("Joy.SDL::GetGPUDriver", SDL_GetGPUDriver);
//	livS_mono_add_internal_call("Joy.SDL::CreateGPUDevice", SDL_CreateGPUDevice);
//	livS_mono_add_internal_call("Joy.SDL::ClaimWindowForGPUDevice", SDL_ClaimWindowForGPUDevice);
//	livS_mono_add_internal_call("Joy.SDL::CreateVertexShader", create_vertex_shader);
//	livS_mono_add_internal_call("Joy.SDL::CreateFragmentShader", create_fragment_shader);
//	livS_mono_add_internal_call("Joy.SDL::CreateGraphicsPipeline", create_graphics_pipeline);
//	livS_mono_add_internal_call("Joy.SDL::CreateAndUploadVertexData", create_and_upload_vertex_data);
//	livS_mono_add_internal_call("Joy.SDL::CreateAndUploadIndicesData", create_and_upload_indices_data);
//	//livS_mono_add_internal_call("Joy.SDL::CreateGPUTexture", create_gpu_texture);
//	livS_mono_add_internal_call("Joy.SDL::CreateGPUSampler", create_gpu_sampler);
//	livS_mono_add_internal_call("Joy.SDL::GPUUpdate", gpu_update);
//	livS_mono_add_internal_call("Joy.SDL::ReleaseGPUSampler", SDL_ReleaseGPUSampler);
//	livS_mono_add_internal_call("Joy.SDL::ReleaseGPUTexture", SDL_ReleaseGPUTexture);
//	livS_mono_add_internal_call("Joy.SDL::ReleaseGPUBuffer", SDL_ReleaseGPUBuffer);
//	livS_mono_add_internal_call("Joy.SDL::ReleaseGPUGraphicsPipeline", SDL_ReleaseGPUGraphicsPipeline);
//	livS_mono_add_internal_call("Joy.SDL::ReleaseGPUShader", SDL_ReleaseGPUShader);
//	livS_mono_add_internal_call("Joy.SDL::ReleaseWindowFromGPUDevice", SDL_ReleaseWindowFromGPUDevice);
//	livS_mono_add_internal_call("Joy.SDL::DestroyGPUDevice", SDL_DestroyGPUDevice);
//	livS_mono_add_internal_call("Joy.SDL::GetMouseState", SDL_GetMouseState);
//	livS_mono_add_internal_call("Joy.SDL::CreateEnvironment", create_environment);
//	livS_mono_add_internal_call("Joy.SDL::GetEnvironmentVariable", get_environment_variable);
//	livS_mono_add_internal_call("Joy.SDL::SetEnvironmentVariable", set_environment_variable);
//	livS_mono_add_internal_call("Joy.SDL::DestroyEnvironment", SDL_DestroyEnvironment);
//	livS_mono_add_internal_call("Joy.SDL::GetEventType", get_event_type);
//	livS_mono_add_internal_call("Joy.SDL::GetEventScancode", get_event_scancode);
//	livS_mono_add_internal_call("Joy.SDL::CreateThread", create_thread);
//
//
//	livS_mono_add_internal_call("Joy.SDL::GetPersonName", get_person_name);
//	livS_mono_add_internal_call("Joy.SDL::GetPersonAge", get_person_age);
//	livS_mono_add_internal_call("Joy.SDL::GetPersonScore", get_person_score);
//
//	livS_mono_add_internal_call("Joy.SDL::SetRenderLogicalPresentation", SDL_SetRenderLogicalPresentation);
//	livS_mono_add_internal_call("Joy.SDL::GetRenderLogicalPresentation", SDL_GetRenderLogicalPresentation);
//	livS_mono_add_internal_call("Joy.SDL::GetRenderLogicalPresentationRect", SDL_GetRenderLogicalPresentationRect);
//}
