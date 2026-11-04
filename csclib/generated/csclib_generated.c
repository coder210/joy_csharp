/* 自动生成，勿手改：tools/gen_csclib.js */
#include <stdint.h>
#include <mono/metadata/object.h>
#include <mono/metadata/appdomain.h>
#include "csclib.h"
#include "joy_csharp.h"
#include <joy/joy.h>

static intptr_t w_lcg_random_create(uint64_t seed)
{
        intptr_t _ret = (intptr_t)lcg_random_create(seed);
        return _ret;
}

static void w_lcg_random_destroy(intptr_t lcg)
{
        lcg_random_destroy((lcg_num_p)lcg);
}

static uint32_t w_lcg_random_next(intptr_t lcg)
{
        uint32_t _ret = lcg_random_next((lcg_num_p)lcg);
        return _ret;
}

static void w_lcg_random_set_state(intptr_t lcg, uint64_t state)
{
        lcg_random_set_state((lcg_num_p)lcg, state);
}

static void w_jpm_config_add_spawn(intptr_t cfg, int cx10, int cz10, int radius10)
{
        jpm_config_add_spawn((jpm_config_p)cfg, cx10, cz10, radius10);
}

static uint32_t w_jpm_wave_seed(uint32_t base_seed, int wave)
{
        uint32_t _ret = jpm_wave_seed(base_seed, wave);
        return _ret;
}

static void w_jtimer_destroy(intptr_t timer)
{
        jtimer_destroy((jtimer_p)timer);
}

static void w_jtimer_trigger(intptr_t timer)
{
        jtimer_trigger((jtimer_p)timer);
}

static void w_jtimer_set_interval(intptr_t timer, int interval)
{
        jtimer_set_interval((jtimer_p)timer, interval);
}

static void w_jtimer_set_active(intptr_t timer, bool active)
{
        jtimer_set_active((jtimer_p)timer, active);
}

static void w_jtimer_reset(intptr_t timer)
{
        jtimer_reset((jtimer_p)timer);
}

static uint64_t w_jtimer_get_elapsed(intptr_t timer)
{
        uint64_t _ret = jtimer_get_elapsed((jtimer_p)timer);
        return _ret;
}

static bool w_init_env(void)
{
        bool _ret = init_env();
        return _ret;
}

static void w_quit_env(void)
{
        quit_env();
}

static uint64_t w_get_ticks(void)
{
        uint64_t _ret = get_ticks();
        return _ret;
}

static int w_get_mouse_button(intptr_t event)
{
        int _ret = get_mouse_button((void*)event);
        return _ret;
}

static intptr_t w_create_window(MonoString* title, int w, int h)
{
        char* s_title = mono_string_to_utf8(title);
        intptr_t _ret = (intptr_t)create_window(s_title, w, h);
        mono_free(s_title);
        return _ret;
}

static void w_destroy_window(intptr_t win)
{
        destroy_window((jwindow_p)win);
}

static intptr_t w_get_raw_window(intptr_t win)
{
        intptr_t _ret = (intptr_t)get_raw_window((jwindow_p)win);
        return _ret;
}

static void w_window_set_fullscreen(intptr_t win, bool fullscreen)
{
        window_set_fullscreen((jwindow_p)win, fullscreen);
}

static bool w_window_get_fullscreen(intptr_t win)
{
        bool _ret = window_get_fullscreen((jwindow_p)win);
        return _ret;
}

static void w_window_set_icon(intptr_t win, MonoString* png_path)
{
        char* s_png_path = mono_string_to_utf8(png_path);
        window_set_icon((jwindow_p)win, s_png_path);
        mono_free(s_png_path);
}

static int w_get_event_type(intptr_t event)
{
        int _ret = get_event_type((void*)event);
        return _ret;
}

static int w_get_event_code(intptr_t event)
{
        int _ret = get_event_code((void*)event);
        return _ret;
}

static bool w_is_user_event(intptr_t event, int type)
{
        bool _ret = is_user_event((void*)event, type);
        return _ret;
}

static bool w_push_user_event(int type, int code)
{
        bool _ret = push_user_event(type, code);
        return _ret;
}

static bool w_push_quit_event(void)
{
        bool _ret = push_quit_event();
        return _ret;
}

static bool w_should_close(intptr_t ev)
{
        bool _ret = should_close((void*)ev);
        return _ret;
}

static void w_log_title(int type)
{
        log_title(type);
}

static intptr_t w_env_create(void)
{
        intptr_t _ret = (intptr_t)env_create();
        return _ret;
}

static void w_env_set(intptr_t env, MonoString* key, MonoString* value)
{
        char* s_key = mono_string_to_utf8(key);
        char* s_value = mono_string_to_utf8(value);
        env_set((env_p)env, s_key, s_value);
        mono_free(s_key);
        mono_free(s_value);
}

static void w_env_destroy(intptr_t env)
{
        env_destroy((env_p)env);
}

static intptr_t w_simple_fps_create(void)
{
        intptr_t _ret = (intptr_t)simple_fps_create();
        return _ret;
}

static void w_simple_fps_destory(intptr_t fps)
{
        simple_fps_destory((simple_fps_counter_p)fps);
}

static void w_simple_fps_update(intptr_t fps)
{
        simple_fps_update((simple_fps_counter_p)fps);
}

static int w_simple_fps_value(intptr_t fps)
{
        int _ret = simple_fps_value((simple_fps_counter_p)fps);
        return _ret;
}

static void w_game_timer_init(intptr_t clock)
{
        game_timer_init((game_timer_p)clock);
}

static void w_game_timer_update(intptr_t clock)
{
        game_timer_update((game_timer_p)clock);
}

static float w_game_timer_get_delta_time(intptr_t clock)
{
        float _ret = game_timer_get_delta_time((game_timer_p)clock);
        return _ret;
}

static float w_game_timer_get_unscaled_delta_time(intptr_t clock)
{
        float _ret = game_timer_get_unscaled_delta_time((game_timer_p)clock);
        return _ret;
}

static void w_game_timer_set_time_scale(intptr_t clock, float scale)
{
        game_timer_set_time_scale((game_timer_p)clock, scale);
}

static float w_game_timer_get_time_scale(intptr_t clock)
{
        float _ret = game_timer_get_time_scale((game_timer_p)clock);
        return _ret;
}

static void w_game_timer_set_target_fps(intptr_t clock, int fps)
{
        game_timer_set_target_fps((game_timer_p)clock, fps);
}

static int w_game_timer_get_target_fps(intptr_t clock)
{
        int _ret = game_timer_get_target_fps((game_timer_p)clock);
        return _ret;
}

static void w_set_clipboard_text(MonoString* text)
{
        char* s_text = mono_string_to_utf8(text);
        set_clipboard_text(s_text);
        mono_free(s_text);
}

static bool w_sys_init_netenv(void)
{
        bool _ret = sys_init_netenv();
        return _ret;
}

static bool w_sys_release_netenv(void)
{
        bool _ret = sys_release_netenv();
        return _ret;
}

static int w_sys_anyaddr(void)
{
        int _ret = sys_anyaddr();
        return _ret;
}

static bool w_sys_closesocket(int64_t sockfd)
{
        bool _ret = sys_closesocket(sockfd);
        return _ret;
}

static int w_sys_set_sock_sndtimeo(int64_t sockfd, int ms)
{
        int _ret = sys_set_sock_sndtimeo(sockfd, ms);
        return _ret;
}

static int w_sys_set_sock_rcvtimeo(int64_t sockfd, int ms)
{
        int _ret = sys_set_sock_rcvtimeo(sockfd, ms);
        return _ret;
}

static int w_sys_set_sock_accpettimeo(int64_t sockfd, int ms)
{
        int _ret = sys_set_sock_accpettimeo(sockfd, ms);
        return _ret;
}

static int w_sys_set_sock_broadcast(int64_t sockfd)
{
        int _ret = sys_set_sock_broadcast(sockfd);
        return _ret;
}

static int w_sys_set_sock_reuseaddr(int64_t sockfd)
{
        int _ret = sys_set_sock_reuseaddr(sockfd);
        return _ret;
}

static int64_t w_sys_tcp(void)
{
        int64_t _ret = sys_tcp();
        return _ret;
}

static int64_t w_sys_udp(void)
{
        int64_t _ret = sys_udp();
        return _ret;
}

static bool w_sys_bind(int64_t sockfd, MonoString* ip, int port)
{
        char* s_ip = mono_string_to_utf8(ip);
        bool _ret = sys_bind(sockfd, s_ip, port);
        mono_free(s_ip);
        return _ret;
}

static bool w_sys_connect(int64_t sockfd, MonoString* ip, int port)
{
        char* s_ip = mono_string_to_utf8(ip);
        bool _ret = sys_connect(sockfd, s_ip, port);
        mono_free(s_ip);
        return _ret;
}

static bool w_sys_listen(int64_t sockfd)
{
        bool _ret = sys_listen(sockfd);
        return _ret;
}

static int w_sys_send(int64_t sockfd, MonoString* buf, int len)
{
        char* s_buf = mono_string_to_utf8(buf);
        int _ret = sys_send(sockfd, s_buf, len);
        mono_free(s_buf);
        return _ret;
}

static int w_sys_sendto(int64_t sockfd, MonoString* buf, int len, MonoString* ip, int port)
{
        char* s_buf = mono_string_to_utf8(buf);
        char* s_ip = mono_string_to_utf8(ip);
        int _ret = sys_sendto(sockfd, s_buf, len, s_ip, port);
        mono_free(s_buf);
        mono_free(s_ip);
        return _ret;
}

static int64_t w_sys_current_time(void)
{
        int64_t _ret = sys_current_time();
        return _ret;
}

static void w_sys_sleep(int ms)
{
        sys_sleep(ms);
}

static void w_sys_install_crash_handlers(void)
{
        sys_install_crash_handlers();
}

static intptr_t w_iocp_server_create(MonoString* bind_ip, int bind_port)
{
        char* s_bind_ip = mono_string_to_utf8(bind_ip);
        intptr_t _ret = (intptr_t)iocp_server_create(s_bind_ip, bind_port);
        mono_free(s_bind_ip);
        return _ret;
}

static void w_iocp_server_destroy(intptr_t server)
{
        iocp_server_destroy((iocp_server_p)server);
}

static void w_iocp_process_events(intptr_t server, int timeout_ms)
{
        iocp_process_events((iocp_server_p)server, timeout_ms);
}

static intptr_t w_font_create(MonoString* filename, int fontsize)
{
        char* s_filename = mono_string_to_utf8(filename);
        intptr_t _ret = (intptr_t)font_create(s_filename, fontsize);
        mono_free(s_filename);
        return _ret;
}

static void w_font_destroy(intptr_t font)
{
        font_destroy((font_p)font);
}

static float w_font_get_scale(intptr_t font)
{
        float _ret = font_get_scale((font_p)font);
        return _ret;
}

static int w_font_get_size(intptr_t font)
{
        int _ret = font_get_size((font_p)font);
        return _ret;
}

static int w_font_get_ascent(intptr_t font)
{
        int _ret = font_get_ascent((font_p)font);
        return _ret;
}

static intptr_t w_r2d_create(intptr_t win)
{
        intptr_t _ret = (intptr_t)r2d_create((jwindow_p)win);
        return _ret;
}

static intptr_t w_r2d_wrap(intptr_t sdl_renderer)
{
        intptr_t _ret = (intptr_t)r2d_wrap((void*)sdl_renderer);
        return _ret;
}

static void w_r2d_destroy(intptr_t r2d)
{
        r2d_destroy((jr2d_p)r2d);
}

static intptr_t w_r2d_unwrap(intptr_t r2d)
{
        intptr_t _ret = (intptr_t)r2d_unwrap((jr2d_p)r2d);
        return _ret;
}

static void w_r2d_begin(intptr_t r2d)
{
        r2d_begin((jr2d_p)r2d);
}

static void w_r2d_end(intptr_t r2d)
{
        r2d_end((jr2d_p)r2d);
}

static bool w_r2d_set_logical_presentation(intptr_t r2d, int w, int h)
{
        bool _ret = r2d_set_logical_presentation((jr2d_p)r2d, w, h);
        return _ret;
}

static bool w_r2d_set_logical_presentation_mode(intptr_t r2d, int w, int h, int mode)
{
        bool _ret = r2d_set_logical_presentation_mode((jr2d_p)r2d, w, h, mode);
        return _ret;
}

static bool w_r2d_set_vsync(intptr_t r2d, int vsync)
{
        bool _ret = r2d_set_vsync((jr2d_p)r2d, vsync);
        return _ret;
}

static bool w_r2d_set_scale(intptr_t r2d, float sx, float sy)
{
        bool _ret = r2d_set_scale((jr2d_p)r2d, sx, sy);
        return _ret;
}

static void w_r2d_set_colorf(intptr_t r2d, float r, float g, float b, float a)
{
        r2d_set_colorf((jr2d_p)r2d, r, g, b, a);
}

static bool w_r2d_set_blend_mode(intptr_t r2d, int mode)
{
        bool _ret = r2d_set_blend_mode((jr2d_p)r2d, mode);
        return _ret;
}

static bool w_r2d_draw_point(intptr_t r2d, float x, float y)
{
        bool _ret = r2d_draw_point((jr2d_p)r2d, x, y);
        return _ret;
}

static void w_r2d_clear_clip(intptr_t r2d)
{
        r2d_clear_clip((jr2d_p)r2d);
}

static void w_r2d_pop_clip_rect(intptr_t r2d)
{
        r2d_pop_clip_rect((jr2d_p)r2d);
}

static void w_r2d_reset_clip_stack(intptr_t r2d)
{
        r2d_reset_clip_stack((jr2d_p)r2d);
}

static bool w_r2d_point_in_clip(intptr_t r2d, float x, float y)
{
        bool _ret = r2d_point_in_clip((jr2d_p)r2d, x, y);
        return _ret;
}

static bool w_shape_draw_line(intptr_t r2d, float x1, float y1, float x2, float y2)
{
        bool _ret = shape_draw_line((jr2d_p)r2d, x1, y1, x2, y2);
        return _ret;
}

static intptr_t w_image_create(intptr_t r2d, MonoString* filename)
{
        char* s_filename = mono_string_to_utf8(filename);
        intptr_t _ret = (intptr_t)image_create((jr2d_p)r2d, s_filename);
        mono_free(s_filename);
        return _ret;
}

static intptr_t w_image_create_from_data(intptr_t r2d, intptr_t rgba_pixels, int w, int h)
{
        intptr_t _ret = (intptr_t)image_create_from_data((jr2d_p)r2d, (void*)rgba_pixels, w, h);
        return _ret;
}

static intptr_t w_image_create_empty(intptr_t r2d, int w, int h)
{
        intptr_t _ret = (intptr_t)image_create_empty((jr2d_p)r2d, w, h);
        return _ret;
}

static void w_image_destroy(intptr_t image)
{
        image_destroy((image_p)image);
}

static void w_image_set_blend_mode(intptr_t image, int mode)
{
        image_set_blend_mode((image_p)image, mode);
}

static void w_image_set_scale_mode(intptr_t image, int nearest)
{
        image_set_scale_mode((image_p)image, nearest);
}

static void w_text_destroy(intptr_t jtext_tex)
{
        text_destroy((jtext_p)jtext_tex);
}

static void w_jtext_print(intptr_t r2d, intptr_t jtext_tex, float x, float y)
{
        jtext_print((jr2d_p)r2d, (jtext_p)jtext_tex, x, y);
}

static bool w_r2d_draw_point_f(intptr_t r2d, float fx, float fy)
{
        bool _ret = r2d_draw_point_f((jr2d_p)r2d, fx, fy);
        return _ret;
}

static bool w_shape_draw_rectangle_f(intptr_t r2d, MonoString* mode, float fx, float fy, float fw, float fh)
{
        char* s_mode = mono_string_to_utf8(mode);
        bool _ret = shape_draw_rectangle_f((jr2d_p)r2d, s_mode, fx, fy, fw, fh);
        mono_free(s_mode);
        return _ret;
}

static bool w_shape_draw_line_f(intptr_t r2d, float fx1, float fy1, float fx2, float fy2)
{
        bool _ret = shape_draw_line_f((jr2d_p)r2d, fx1, fy1, fx2, fy2);
        return _ret;
}

static int w_text_get_width(intptr_t jtext_tex)
{
        int _ret = text_get_width((jtext_p)jtext_tex);
        return _ret;
}

static int w_text_get_height(intptr_t jtext_tex)
{
        int _ret = text_get_height((jtext_p)jtext_tex);
        return _ret;
}

static void w_jtext_cache_clear(void)
{
        jtext_cache_clear();
}

static void w_jtext_cache_set_limit(int max_entries)
{
        jtext_cache_set_limit(max_entries);
}

static int w_jtext_cache_get_count(void)
{
        int _ret = jtext_cache_get_count();
        return _ret;
}

static void w_jtext_cache_sweep(int max_idle_frames)
{
        jtext_cache_sweep(max_idle_frames);
}

static intptr_t w_animation_create(intptr_t r2d)
{
        intptr_t _ret = (intptr_t)animation_create((jr2d_p)r2d);
        return _ret;
}

static void w_animation_destroy(intptr_t animation)
{
        animation_destroy((animation_p)animation);
}

static void w_animation_reset(intptr_t animation)
{
        animation_reset((animation_p)animation);
}

static bool w_animation_is_finished(intptr_t animation)
{
        bool _ret = animation_is_finished((animation_p)animation);
        return _ret;
}

static void w_animation_set_position(intptr_t animation, float x, float y)
{
        animation_set_position((animation_p)animation, x, y);
}

static void w_animation_set_scale(intptr_t animation, float x, float y)
{
        animation_set_scale((animation_p)animation, x, y);
}

static void w_animation_set_rotation(intptr_t animation, float rotation)
{
        animation_set_rotation((animation_p)animation, rotation);
}

static void w_animation_update(intptr_t animation, float dt)
{
        animation_update((animation_p)animation, dt);
}

static intptr_t w_r3d_load_shader(intptr_t device, MonoString* filename, int stage, int sampler_num, int uniform_buffer_num)
{
        char* s_filename = mono_string_to_utf8(filename);
        intptr_t _ret = (intptr_t)r3d_load_shader((void*)device, s_filename, stage, sampler_num, uniform_buffer_num);
        mono_free(s_filename);
        return _ret;
}

static intptr_t w_r3d_create_pipeline(intptr_t device, intptr_t vertex_shader, intptr_t fragment_shader, int swapchain_format, int depth_format)
{
        intptr_t _ret = (intptr_t)r3d_create_pipeline((void*)device, (void*)vertex_shader, (void*)fragment_shader, swapchain_format, depth_format);
        return _ret;
}

static intptr_t w_r3d_upload_buffer(intptr_t device, intptr_t data, size_t size)
{
        intptr_t _ret = (intptr_t)r3d_upload_buffer((void*)device, (void*)data, size);
        return _ret;
}

static intptr_t w_r3d_create_depth_texture(intptr_t device, int width, int height)
{
        intptr_t _ret = (intptr_t)r3d_create_depth_texture((void*)device, width, height);
        return _ret;
}

static intptr_t w_r3d_create_sampler(intptr_t device)
{
        intptr_t _ret = (intptr_t)r3d_create_sampler((void*)device);
        return _ret;
}

static intptr_t w_r3d_create(intptr_t win, MonoString* shader_dir)
{
        char* s_shader_dir = mono_string_to_utf8(shader_dir);
        intptr_t _ret = (intptr_t)r3d_create((jwindow_p)win, s_shader_dir);
        mono_free(s_shader_dir);
        return _ret;
}

static void w_r3d_destroy(intptr_t r)
{
        r3d_destroy((jr3d_p)r);
}

static intptr_t w_r3d_get_device(intptr_t r)
{
        intptr_t _ret = (intptr_t)r3d_get_device((jr3d_p)r);
        return _ret;
}

static bool w_r3d_begin(intptr_t r)
{
        bool _ret = r3d_begin((jr3d_p)r);
        return _ret;
}

static void w_r3d_end(intptr_t r)
{
        r3d_end((jr3d_p)r);
}

static int w_r3d_get_draw_calls(intptr_t r)
{
        int _ret = r3d_get_draw_calls((jr3d_p)r);
        return _ret;
}

static intptr_t w_r3d_mesh_cube(intptr_t r, float w, float h, float d)
{
        intptr_t _ret = (intptr_t)r3d_mesh_cube((jr3d_p)r, w, h, d);
        return _ret;
}

static intptr_t w_r3d_mesh_sphere(intptr_t r, float radius, int slices, int stacks)
{
        intptr_t _ret = (intptr_t)r3d_mesh_sphere((jr3d_p)r, radius, slices, stacks);
        return _ret;
}

static intptr_t w_r3d_mesh_plane(intptr_t r, float w, float d, int segs)
{
        intptr_t _ret = (intptr_t)r3d_mesh_plane((jr3d_p)r, w, d, segs);
        return _ret;
}

static intptr_t w_r3d_mesh_ramp(intptr_t r, float w, float l, float h)
{
        intptr_t _ret = (intptr_t)r3d_mesh_ramp((jr3d_p)r, w, l, h);
        return _ret;
}

static intptr_t w_r3d_mesh_custom(intptr_t r, intptr_t verts, int vertex_count)
{
        intptr_t _ret = (intptr_t)r3d_mesh_custom((jr3d_p)r, (void*)verts, vertex_count);
        return _ret;
}

static intptr_t w_r3d_mesh_quad(intptr_t r)
{
        intptr_t _ret = (intptr_t)r3d_mesh_quad((jr3d_p)r);
        return _ret;
}

static intptr_t w_r3d_mesh_cube_wire(intptr_t r, float w, float h, float d)
{
        intptr_t _ret = (intptr_t)r3d_mesh_cube_wire((jr3d_p)r, w, h, d);
        return _ret;
}

static intptr_t w_r3d_mesh_sphere_wire(intptr_t r, float radius, int slices, int stacks)
{
        intptr_t _ret = (intptr_t)r3d_mesh_sphere_wire((jr3d_p)r, radius, slices, stacks);
        return _ret;
}

static intptr_t w_r3d_mesh_plane_wire(intptr_t r, float w, float d, int segs)
{
        intptr_t _ret = (intptr_t)r3d_mesh_plane_wire((jr3d_p)r, w, d, segs);
        return _ret;
}

static intptr_t w_r3d_mesh_ramp_wire(intptr_t r, float w, float l, float h)
{
        intptr_t _ret = (intptr_t)r3d_mesh_ramp_wire((jr3d_p)r, w, l, h);
        return _ret;
}

static void w_r3d_mesh_destroy(intptr_t r, intptr_t m)
{
        r3d_mesh_destroy((jr3d_p)r, (render_mesh_p)m);
}

static intptr_t w_r3d_create_texture(intptr_t r, int w, int h, intptr_t rgba32, int flip)
{
        intptr_t _ret = (intptr_t)r3d_create_texture((jr3d_p)r, w, h, (void*)rgba32, flip);
        return _ret;
}

static intptr_t w_r3d_gen_checkerboard(intptr_t r, int tile_size, int tile_count)
{
        intptr_t _ret = (intptr_t)r3d_gen_checkerboard((jr3d_p)r, tile_size, tile_count);
        return _ret;
}

static bool w_r3d_font_init(intptr_t r, MonoString* ttf_path, int pixel_height)
{
        char* s_ttf_path = mono_string_to_utf8(ttf_path);
        bool _ret = r3d_font_init((jr3d_p)r, s_ttf_path, pixel_height);
        mono_free(s_ttf_path);
        return _ret;
}

static bool w_r3d_font_draw_2d(intptr_t r, intptr_t m, MonoString* text, float pixelX, float pixelY, float fontSize, float winW, float winH)
{
        char* s_text = mono_string_to_utf8(text);
        bool _ret = r3d_font_draw_2d((jr3d_p)r, (render_mesh_p)m, s_text, pixelX, pixelY, fontSize, winW, winH);
        mono_free(s_text);
        return _ret;
}

static void w_r3d_font_cache_set_limit(intptr_t r, int max_entries)
{
        r3d_font_cache_set_limit((jr3d_p)r, max_entries);
}

static int w_r3d_font_cache_get_count(intptr_t r)
{
        int _ret = r3d_font_cache_get_count((jr3d_p)r);
        return _ret;
}

static void w_r3d_font_cache_clear(intptr_t r)
{
        r3d_font_cache_clear((jr3d_p)r);
}

static void w_r3d_font_cache_sweep(intptr_t r, int max_idle_frames)
{
        r3d_font_cache_sweep((jr3d_p)r, max_idle_frames);
}

static void w_r3d_set_logical_presentation(intptr_t r, int w, int h)
{
        r3d_set_logical_presentation((jr3d_p)r, w, h);
}

static void w_r3d_set_logical_presentation_mode(intptr_t r, int w, int h, int mode)
{
        r3d_set_logical_presentation_mode((jr3d_p)r, w, h, mode);
}

static intptr_t w_r3d_button_create(float x, float y, float w, float h, MonoString* text)
{
        char* s_text = mono_string_to_utf8(text);
        intptr_t _ret = (intptr_t)r3d_button_create(x, y, w, h, s_text);
        mono_free(s_text);
        return _ret;
}

static void w_r3d_button_draw(intptr_t r, intptr_t m, intptr_t btn, float winW, float winH)
{
        r3d_button_draw((jr3d_p)r, (render_mesh_p)m, (jr3d_button_p)btn, winW, winH);
}

static void w_r3d_button_draw_circle(intptr_t r, intptr_t m, intptr_t btn, float winW, float winH)
{
        r3d_button_draw_circle((jr3d_p)r, (render_mesh_p)m, (jr3d_button_p)btn, winW, winH);
}

static bool w_r3d_button_is_hovered(intptr_t r, intptr_t btn, float mx, float my)
{
        bool _ret = r3d_button_is_hovered((jr3d_p)r, (jr3d_button_p)btn, mx, my);
        return _ret;
}

static bool w_r3d_button_is_pressed(intptr_t r, intptr_t btn, bool mouse_down, float mx, float my)
{
        bool _ret = r3d_button_is_pressed((jr3d_p)r, (jr3d_button_p)btn, mouse_down, mx, my);
        return _ret;
}

static void w_r3d_button_release(intptr_t r, intptr_t btn, float mx, float my)
{
        r3d_button_release((jr3d_p)r, (jr3d_button_p)btn, mx, my);
}

static void w_r3d_button_destroy(intptr_t btn)
{
        r3d_button_destroy((jr3d_button_p)btn);
}

static void w_r3d_draw_tex_2d(intptr_t r, intptr_t m, float x, float y, float w, float h, intptr_t tex, float winW, float winH)
{
        r3d_draw_tex_2d((jr3d_p)r, (render_mesh_p)m, x, y, w, h, (void*)tex, winW, winH);
}

static void w_r3d_label_set_text(intptr_t l, MonoString* text)
{
        char* s_text = mono_string_to_utf8(text);
        r3d_label_set_text((jr3d_label_p)l, s_text);
        mono_free(s_text);
}

static void w_r3d_label_draw(intptr_t r, intptr_t m, intptr_t l, float winW, float winH)
{
        r3d_label_draw((jr3d_p)r, (render_mesh_p)m, (jr3d_label_p)l, winW, winH);
}

static void w_r3d_label_destroy(intptr_t l)
{
        r3d_label_destroy((jr3d_label_p)l);
}

static void w_r3d_input_set_text(intptr_t inp, MonoString* text)
{
        char* s_text = mono_string_to_utf8(text);
        r3d_input_set_text((jr3d_input_p)inp, s_text);
        mono_free(s_text);
}

static bool w_r3d_input_is_hovered(intptr_t r, intptr_t inp, float mx, float my)
{
        bool _ret = r3d_input_is_hovered((jr3d_p)r, (jr3d_input_p)inp, mx, my);
        return _ret;
}

static void w_r3d_input_focus(intptr_t inp)
{
        r3d_input_focus((jr3d_input_p)inp);
}

static void w_r3d_input_defocus(intptr_t inp)
{
        r3d_input_defocus((jr3d_input_p)inp);
}

static bool w_r3d_input_is_focused(intptr_t inp)
{
        bool _ret = r3d_input_is_focused((jr3d_input_p)inp);
        return _ret;
}

static void w_r3d_input_start_text_input(intptr_t r, intptr_t inp)
{
        r3d_input_start_text_input((jr3d_p)r, (jr3d_input_p)inp);
}

static void w_r3d_input_stop_text_input(intptr_t r, intptr_t inp)
{
        r3d_input_stop_text_input((jr3d_p)r, (jr3d_input_p)inp);
}

static void w_r3d_input_insert(intptr_t inp, MonoString* s)
{
        char* s_s = mono_string_to_utf8(s);
        r3d_input_insert((jr3d_input_p)inp, s_s);
        mono_free(s_s);
}

static void w_r3d_input_backspace(intptr_t inp)
{
        r3d_input_backspace((jr3d_input_p)inp);
}

static void w_r3d_input_delete(intptr_t inp)
{
        r3d_input_delete((jr3d_input_p)inp);
}

static void w_r3d_input_cursor_left(intptr_t inp)
{
        r3d_input_cursor_left((jr3d_input_p)inp);
}

static void w_r3d_input_cursor_right(intptr_t inp)
{
        r3d_input_cursor_right((jr3d_input_p)inp);
}

static void w_r3d_input_cursor_home(intptr_t inp)
{
        r3d_input_cursor_home((jr3d_input_p)inp);
}

static void w_r3d_input_cursor_end(intptr_t inp)
{
        r3d_input_cursor_end((jr3d_input_p)inp);
}

static void w_r3d_input_click(intptr_t r, intptr_t inp, float mx, float my)
{
        r3d_input_click((jr3d_p)r, (jr3d_input_p)inp, mx, my);
}

static void w_r3d_input_submit(intptr_t inp)
{
        r3d_input_submit((jr3d_input_p)inp);
}

static void w_r3d_input_draw(intptr_t r, intptr_t m, intptr_t inp, float winW, float winH)
{
        r3d_input_draw((jr3d_p)r, (render_mesh_p)m, (jr3d_input_p)inp, winW, winH);
}

static void w_r3d_input_destroy(intptr_t inp)
{
        r3d_input_destroy((jr3d_input_p)inp);
}

static void w_r3d_combobox_input_destroy(intptr_t ci)
{
        r3d_combobox_input_destroy((jr3d_combobox_input_p)ci);
}

static void w_r3d_combobox_input_add_item(intptr_t ci, MonoString* str)
{
        char* s_str = mono_string_to_utf8(str);
        r3d_combobox_input_add_item((jr3d_combobox_input_p)ci, s_str);
        mono_free(s_str);
}

static void w_r3d_combobox_input_clear_items(intptr_t ci)
{
        r3d_combobox_input_clear_items((jr3d_combobox_input_p)ci);
}

static void w_r3d_combobox_input_set_text(intptr_t ci, MonoString* str)
{
        char* s_str = mono_string_to_utf8(str);
        r3d_combobox_input_set_text((jr3d_combobox_input_p)ci, s_str);
        mono_free(s_str);
}

static int w_r3d_combobox_input_hit_item(intptr_t ci, float x, float y)
{
        int _ret = r3d_combobox_input_hit_item((jr3d_combobox_input_p)ci, x, y);
        return _ret;
}

static void w_r3d_combobox_input_draw(intptr_t r, intptr_t m, intptr_t ci, float winW, float winH)
{
        r3d_combobox_input_draw((jr3d_p)r, (render_mesh_p)m, (jr3d_combobox_input_p)ci, winW, winH);
}

static void w_r3d_combobox_input_draw_dropdown(intptr_t r, intptr_t m, intptr_t ci, float winW, float winH)
{
        r3d_combobox_input_draw_dropdown((jr3d_p)r, (render_mesh_p)m, (jr3d_combobox_input_p)ci, winW, winH);
}

static intptr_t w_r3d_slider_create(float x, float y, float w, float h, float min, float max, float initial)
{
        intptr_t _ret = (intptr_t)r3d_slider_create(x, y, w, h, min, max, initial);
        return _ret;
}

static void w_r3d_slider_destroy(intptr_t s)
{
        r3d_slider_destroy((jr3d_slider_p)s);
}

static void w_r3d_slider_set_value(intptr_t s, float v)
{
        r3d_slider_set_value((jr3d_slider_p)s, v);
}

static float w_r3d_slider_get_value(intptr_t s)
{
        float _ret = r3d_slider_get_value((jr3d_slider_p)s);
        return _ret;
}

static void w_r3d_slider_draw(intptr_t r, intptr_t m, intptr_t s, float winW, float winH)
{
        r3d_slider_draw((jr3d_p)r, (render_mesh_p)m, (jr3d_slider_p)s, winW, winH);
}

static bool w_r3d_slider_is_pressed(intptr_t r, intptr_t s, float x, float y)
{
        bool _ret = r3d_slider_is_pressed((jr3d_p)r, (jr3d_slider_p)s, x, y);
        return _ret;
}

static void w_r3d_slider_set_pressed(intptr_t s, bool v)
{
        r3d_slider_set_pressed((jr3d_slider_p)s, v);
}

static void w_r3d_slider_drag_move(intptr_t r, intptr_t s, float x, float y)
{
        r3d_slider_drag_move((jr3d_p)r, (jr3d_slider_p)s, x, y);
}

static bool w_r3d_slider_is_hovered(intptr_t r, intptr_t s, float x, float y)
{
        bool _ret = r3d_slider_is_hovered((jr3d_p)r, (jr3d_slider_p)s, x, y);
        return _ret;
}

static void w_r3d_slider_set_hovered(intptr_t s, bool v)
{
        r3d_slider_set_hovered((jr3d_slider_p)s, v);
}

static intptr_t w_r3d_checkbox_create(float x, float y, float size, MonoString* label)
{
        char* s_label = mono_string_to_utf8(label);
        intptr_t _ret = (intptr_t)r3d_checkbox_create(x, y, size, s_label);
        mono_free(s_label);
        return _ret;
}

static void w_r3d_checkbox_destroy(intptr_t cb)
{
        r3d_checkbox_destroy((jr3d_checkbox_p)cb);
}

static void w_r3d_checkbox_toggle(intptr_t cb)
{
        r3d_checkbox_toggle((jr3d_checkbox_p)cb);
}

static bool w_r3d_checkbox_is_pressed(intptr_t r, intptr_t cb, float x, float y)
{
        bool _ret = r3d_checkbox_is_pressed((jr3d_p)r, (jr3d_checkbox_p)cb, x, y);
        return _ret;
}

static void w_r3d_checkbox_set_hovered(intptr_t cb, bool v)
{
        r3d_checkbox_set_hovered((jr3d_checkbox_p)cb, v);
}

static bool w_r3d_checkbox_is_hovered(intptr_t r, intptr_t cb, float x, float y)
{
        bool _ret = r3d_checkbox_is_hovered((jr3d_p)r, (jr3d_checkbox_p)cb, x, y);
        return _ret;
}

static void w_r3d_checkbox_draw(intptr_t r, intptr_t m, intptr_t cb, float winW, float winH)
{
        r3d_checkbox_draw((jr3d_p)r, (render_mesh_p)m, (jr3d_checkbox_p)cb, winW, winH);
}

static void w_r3d_draw_grid(intptr_t r, int slices, float spacing, float line_width)
{
        r3d_draw_grid((jr3d_p)r, slices, spacing, line_width);
}

static intptr_t w_r3d_create_line_pipeline(intptr_t device, intptr_t vertex_shader, intptr_t fragment_shader, int swapchain_format, int depth_format)
{
        intptr_t _ret = (intptr_t)r3d_create_line_pipeline((void*)device, (void*)vertex_shader, (void*)fragment_shader, swapchain_format, depth_format);
        return _ret;
}

static intptr_t w_r3d_create_lighting_pipeline(intptr_t device, intptr_t vertex_shader, intptr_t fragment_shader, int swapchain_format, int depth_format)
{
        intptr_t _ret = (intptr_t)r3d_create_lighting_pipeline((void*)device, (void*)vertex_shader, (void*)fragment_shader, swapchain_format, depth_format);
        return _ret;
}

static intptr_t w_r3d_mesh_cube_lit(intptr_t r, float w, float h, float d)
{
        intptr_t _ret = (intptr_t)r3d_mesh_cube_lit((jr3d_p)r, w, h, d);
        return _ret;
}

static intptr_t w_r3d_mesh_sphere_lit(intptr_t r, float radius, int slices, int stacks)
{
        intptr_t _ret = (intptr_t)r3d_mesh_sphere_lit((jr3d_p)r, radius, slices, stacks);
        return _ret;
}

static intptr_t w_r3d_mesh_plane_lit(intptr_t r, float w, float d, int segs)
{
        intptr_t _ret = (intptr_t)r3d_mesh_plane_lit((jr3d_p)r, w, d, segs);
        return _ret;
}

static intptr_t w_r3d_mesh_ramp_lit(intptr_t r, float w, float l, float h)
{
        intptr_t _ret = (intptr_t)r3d_mesh_ramp_lit((jr3d_p)r, w, l, h);
        return _ret;
}

static intptr_t w_r3d_mesh_custom_lit(intptr_t r, intptr_t verts, int vertex_count)
{
        intptr_t _ret = (intptr_t)r3d_mesh_custom_lit((jr3d_p)r, (void*)verts, vertex_count);
        return _ret;
}

static intptr_t w_janimator_create(intptr_t r2d)
{
        intptr_t _ret = (intptr_t)janimator_create((jr2d_p)r2d);
        return _ret;
}

static void w_janimator_destroy(intptr_t anim)
{
        janimator_destroy((janimator_p)anim);
}

static void w_janimator_set_float(intptr_t anim, MonoString* name, float v)
{
        char* s_name = mono_string_to_utf8(name);
        janimator_set_float((janimator_p)anim, s_name, v);
        mono_free(s_name);
}

static void w_janimator_set_int(intptr_t anim, MonoString* name, int v)
{
        char* s_name = mono_string_to_utf8(name);
        janimator_set_int((janimator_p)anim, s_name, v);
        mono_free(s_name);
}

static void w_janimator_set_bool(intptr_t anim, MonoString* name, bool v)
{
        char* s_name = mono_string_to_utf8(name);
        janimator_set_bool((janimator_p)anim, s_name, v);
        mono_free(s_name);
}

static void w_janimator_set_trigger(intptr_t anim, MonoString* name)
{
        char* s_name = mono_string_to_utf8(name);
        janimator_set_trigger((janimator_p)anim, s_name);
        mono_free(s_name);
}

static float w_janimator_get_float(intptr_t anim, MonoString* name)
{
        char* s_name = mono_string_to_utf8(name);
        float _ret = janimator_get_float((janimator_p)anim, s_name);
        mono_free(s_name);
        return _ret;
}

static int w_janimator_get_int(intptr_t anim, MonoString* name)
{
        char* s_name = mono_string_to_utf8(name);
        int _ret = janimator_get_int((janimator_p)anim, s_name);
        mono_free(s_name);
        return _ret;
}

static bool w_janimator_get_bool(intptr_t anim, MonoString* name)
{
        char* s_name = mono_string_to_utf8(name);
        bool _ret = janimator_get_bool((janimator_p)anim, s_name);
        mono_free(s_name);
        return _ret;
}

static void w_janimator_add_state(intptr_t anim, MonoString* name)
{
        char* s_name = mono_string_to_utf8(name);
        janimator_add_state((janimator_p)anim, s_name);
        mono_free(s_name);
}

static void w_janimator_set_default_state(intptr_t anim, MonoString* name)
{
        char* s_name = mono_string_to_utf8(name);
        janimator_set_default_state((janimator_p)anim, s_name);
        mono_free(s_name);
}

static void w_janimator_state_set_loop(intptr_t anim, MonoString* state_name, bool loop)
{
        char* s_state_name = mono_string_to_utf8(state_name);
        janimator_state_set_loop((janimator_p)anim, s_state_name, loop);
        mono_free(s_state_name);
}

static void w_janimator_state_set_speed(intptr_t anim, MonoString* state_name, float speed)
{
        char* s_state_name = mono_string_to_utf8(state_name);
        janimator_state_set_speed((janimator_p)anim, s_state_name, speed);
        mono_free(s_state_name);
}

static void w_janimator_state_set_blend(intptr_t anim, MonoString* state_name, MonoString* param_name)
{
        char* s_state_name = mono_string_to_utf8(state_name);
        char* s_param_name = mono_string_to_utf8(param_name);
        janimator_state_set_blend((janimator_p)anim, s_state_name, s_param_name);
        mono_free(s_state_name);
        mono_free(s_param_name);
}

static int w_janimator_add_transition(intptr_t anim, MonoString* from, MonoString* to)
{
        char* s_from = mono_string_to_utf8(from);
        char* s_to = mono_string_to_utf8(to);
        int _ret = janimator_add_transition((janimator_p)anim, s_from, s_to);
        mono_free(s_from);
        mono_free(s_to);
        return _ret;
}

static int w_janimator_add_any_transition(intptr_t anim, MonoString* to)
{
        char* s_to = mono_string_to_utf8(to);
        int _ret = janimator_add_any_transition((janimator_p)anim, s_to);
        mono_free(s_to);
        return _ret;
}

static void w_janimator_transition_add_cond(intptr_t anim, int trans_idx, MonoString* param_name, int mode, float threshold)
{
        char* s_param_name = mono_string_to_utf8(param_name);
        janimator_transition_add_cond((janimator_p)anim, trans_idx, s_param_name, mode, threshold);
        mono_free(s_param_name);
}

static void w_janimator_transition_set_exit_time(intptr_t anim, int trans_idx, float seconds)
{
        janimator_transition_set_exit_time((janimator_p)anim, trans_idx, seconds);
}

static void w_janimator_update(intptr_t anim, float dt)
{
        janimator_update((janimator_p)anim, dt);
}

static void w_janimator_draw(intptr_t anim, float x, float y)
{
        janimator_draw((janimator_p)anim, x, y);
}

static void w_janimator_set_flip_h(intptr_t anim, bool flip)
{
        janimator_set_flip_h((janimator_p)anim, flip);
}

static void w_label_destroy(intptr_t label)
{
        label_destroy((label_p)label);
}

static void w_label_draw(intptr_t label)
{
        label_draw((label_p)label);
}

static void w_label_process_event(intptr_t label, intptr_t event)
{
        label_process_event((label_p)label, (void*)event);
}

static intptr_t w_button_create(intptr_t r2d, float cx, float cy, float wf, float hf)
{
        intptr_t _ret = (intptr_t)button_create((jr2d_p)r2d, cx, cy, wf, hf);
        return _ret;
}

static void w_button_destroy(intptr_t btn)
{
        button_destroy((button_p)btn);
}

static void w_button_set_position(intptr_t btn, float x, float y)
{
        button_set_position((button_p)btn, x, y);
}

static void w_button_set_size(intptr_t btn, float width, float height)
{
        button_set_size((button_p)btn, width, height);
}

static void w_button_set_image(intptr_t btn, intptr_t image)
{
        button_set_image((button_p)btn, (image_p)image);
}

static void w_button_set_pressed_image(intptr_t btn, intptr_t image)
{
        button_set_pressed_image((button_p)btn, (image_p)image);
}

static bool w_button_is_hovered(intptr_t btn, float x, float y)
{
        bool _ret = button_is_hovered((button_p)btn, x, y);
        return _ret;
}

static bool w_button_is_pressed(intptr_t btn, float x, float y)
{
        bool _ret = button_is_pressed((button_p)btn, x, y);
        return _ret;
}

static void w_button_set_hovered(intptr_t btn, bool v)
{
        button_set_hovered((button_p)btn, v);
}

static void w_button_set_pressed(intptr_t btn, bool v)
{
        button_set_pressed((button_p)btn, v);
}

static bool w_button_get_pressed(intptr_t btn)
{
        bool _ret = button_get_pressed((button_p)btn);
        return _ret;
}

static void w_button_set_text_offset(intptr_t btn, float x, float y)
{
        button_set_text_offset((button_p)btn, x, y);
}

static void w_button_draw(intptr_t btn)
{
        button_draw((button_p)btn);
}

static void w_button_process_event(intptr_t btn, intptr_t event)
{
        button_process_event((button_p)btn, (void*)event);
}

static intptr_t w_scrollview_create(intptr_t r2d, float fx, float fy, float fw, float fh)
{
        intptr_t _ret = (intptr_t)scrollview_create((jr2d_p)r2d, fx, fy, fw, fh);
        return _ret;
}

static void w_scrollview_destroy(intptr_t v)
{
        scrollview_destroy((scrollview_p)v);
}

static void w_scrollview_set_view_px(intptr_t v, float x, float y, float w, float h)
{
        scrollview_set_view_px((scrollview_p)v, x, y, w, h);
}

static void w_scrollview_set_content(intptr_t v, float content_w, float content_h)
{
        scrollview_set_content((scrollview_p)v, content_w, content_h);
}

static void w_scrollview_set_offset(intptr_t v, float ox, float oy)
{
        scrollview_set_offset((scrollview_p)v, ox, oy);
}

static void w_scrollview_clamp(intptr_t v)
{
        scrollview_clamp((scrollview_p)v);
}

static float w_scrollview_get_offset_x(intptr_t v)
{
        float _ret = scrollview_get_offset_x((scrollview_p)v);
        return _ret;
}

static float w_scrollview_get_offset_y(intptr_t v)
{
        float _ret = scrollview_get_offset_y((scrollview_p)v);
        return _ret;
}

static void w_scrollview_set_show_bar(intptr_t v, bool show)
{
        scrollview_set_show_bar((scrollview_p)v, show);
}

static bool w_scrollview_dragging(intptr_t v)
{
        bool _ret = scrollview_dragging((scrollview_p)v);
        return _ret;
}

static bool w_scrollview_hit(intptr_t v, float win_x, float win_y)
{
        bool _ret = scrollview_hit((scrollview_p)v, win_x, win_y);
        return _ret;
}

static void w_scrollview_begin(intptr_t v)
{
        scrollview_begin((scrollview_p)v);
}

static void w_scrollview_end(intptr_t v)
{
        scrollview_end((scrollview_p)v);
}

static bool w_scrollview_process_event(intptr_t v, intptr_t event)
{
        bool _ret = scrollview_process_event((scrollview_p)v, (void*)event);
        return _ret;
}

static intptr_t w_combobox_create(intptr_t r2d, float fx, float fy, float fw, float fh)
{
        intptr_t _ret = (intptr_t)combobox_create((jr2d_p)r2d, fx, fy, fw, fh);
        return _ret;
}

static void w_combobox_destroy(intptr_t combobox)
{
        combobox_destroy((combobox_p)combobox);
}

static bool w_combobox_is_pressed(intptr_t combobox, float x, float y)
{
        bool _ret = combobox_is_pressed((combobox_p)combobox, x, y);
        return _ret;
}

static bool w_combobox_is_open(intptr_t combobox)
{
        bool _ret = combobox_is_open((combobox_p)combobox);
        return _ret;
}

static void w_combobox_set_open(intptr_t combobox, bool v)
{
        combobox_set_open((combobox_p)combobox, v);
}

static int w_combobox_hit_item(intptr_t combobox, float x, float y)
{
        int _ret = combobox_hit_item((combobox_p)combobox, x, y);
        return _ret;
}

static void w_combobox_set_selected(intptr_t combobox, int index)
{
        combobox_set_selected((combobox_p)combobox, index);
}

static int w_combobox_get_selected(intptr_t combobox)
{
        int _ret = combobox_get_selected((combobox_p)combobox);
        return _ret;
}

static void w_combobox_draw(intptr_t combobox)
{
        combobox_draw((combobox_p)combobox);
}

static void w_combobox_process_event(intptr_t cb, intptr_t event)
{
        combobox_process_event((combobox_p)cb, (void*)event);
}

static intptr_t w_combobox_input_create(intptr_t r2d, float fx, float fy, float fw, float fh, intptr_t font, int buf_len)
{
        intptr_t _ret = (intptr_t)combobox_input_create((jr2d_p)r2d, fx, fy, fw, fh, (font_p)font, buf_len);
        return _ret;
}

static void w_combobox_input_destroy(intptr_t ci)
{
        combobox_input_destroy((combobox_input_p)ci);
}

static void w_combobox_input_add_item(intptr_t ci, MonoString* str, int len)
{
        char* s_str = mono_string_to_utf8(str);
        combobox_input_add_item((combobox_input_p)ci, s_str, len);
        mono_free(s_str);
}

static void w_combobox_input_clear_items(intptr_t ci)
{
        combobox_input_clear_items((combobox_input_p)ci);
}

static void w_combobox_input_set_text(intptr_t ci, MonoString* str)
{
        char* s_str = mono_string_to_utf8(str);
        combobox_input_set_text((combobox_input_p)ci, s_str);
        mono_free(s_str);
}

static void w_combobox_input_draw(intptr_t ci)
{
        combobox_input_draw((combobox_input_p)ci);
}

static void w_combobox_input_draw_dropdown(intptr_t ci)
{
        combobox_input_draw_dropdown((combobox_input_p)ci);
}

static bool w_combobox_input_is_open(intptr_t ci)
{
        bool _ret = combobox_input_is_open((combobox_input_p)ci);
        return _ret;
}

static void w_combobox_input_set_popup_node(intptr_t ci, intptr_t node)
{
        combobox_input_set_popup_node((combobox_input_p)ci, (scene_node_p)node);
}

static void w_combobox_input_process_event(intptr_t ci, intptr_t ev)
{
        combobox_input_process_event((combobox_input_p)ci, (void*)ev);
}

static int w_combobox_input_hit_item(intptr_t ci, float x, float y)
{
        int _ret = combobox_input_hit_item((combobox_input_p)ci, x, y);
        return _ret;
}

static void w_combobox_input_set_open(intptr_t ci, bool v)
{
        combobox_input_set_open((combobox_input_p)ci, v);
}

static intptr_t w_datagrid_create(intptr_t r2d, float fx, float fy, float fw, float fh, int col_count, bool has_header, intptr_t font)
{
        intptr_t _ret = (intptr_t)datagrid_create((jr2d_p)r2d, fx, fy, fw, fh, col_count, has_header, (void*)font);
        return _ret;
}

static void w_datagrid_setheaders(intptr_t grid, MonoString* headers)
{
        char* s_headers = mono_string_to_utf8(headers);
        datagrid_setheaders((datagrid_p)grid, s_headers);
        mono_free(s_headers);
}

static void w_datagrid_setheader(intptr_t grid, int index, MonoString* header)
{
        char* s_header = mono_string_to_utf8(header);
        datagrid_setheader((datagrid_p)grid, index, s_header);
        mono_free(s_header);
}

static void w_datagrid_setcell(intptr_t grid, int row_index, int col_index, MonoString* data)
{
        char* s_data = mono_string_to_utf8(data);
        datagrid_setcell((datagrid_p)grid, row_index, col_index, s_data);
        mono_free(s_data);
}

static void w_datagrid_destroy(intptr_t grid)
{
        datagrid_destroy((datagrid_p)grid);
}

static void w_datagrid_draw(intptr_t grid, intptr_t r2d)
{
        datagrid_draw((datagrid_p)grid, (jr2d_p)r2d);
}

static int w_datagrid_hit_row(intptr_t grid, float x, float y)
{
        int _ret = datagrid_hit_row((datagrid_p)grid, x, y);
        return _ret;
}

static void w_datagrid_scroll(intptr_t grid, int lines)
{
        datagrid_scroll((datagrid_p)grid, lines);
}

static void w_datagrid_set_selected_row(intptr_t grid, int row)
{
        datagrid_set_selected_row((datagrid_p)grid, row);
}

static void w_datagrid_process_event(intptr_t dg, intptr_t event)
{
        datagrid_process_event((datagrid_p)dg, (void*)event);
}

static intptr_t w_radio_create(float fx, float fy, float size_frac, MonoString* label, int group_id)
{
        char* s_label = mono_string_to_utf8(label);
        intptr_t _ret = (intptr_t)radio_create(fx, fy, size_frac, s_label, group_id);
        mono_free(s_label);
        return _ret;
}

static void w_radio_destroy(intptr_t radio)
{
        radio_destroy((radio_p)radio);
}

static bool w_radio_is_pressed(intptr_t radio, float x, float y)
{
        bool _ret = radio_is_pressed((radio_p)radio, x, y);
        return _ret;
}

static void w_radio_set_hovered(intptr_t radio, bool v)
{
        radio_set_hovered((radio_p)radio, v);
}

static void w_radio_process_event(intptr_t rb, intptr_t event)
{
        radio_process_event((radio_p)rb, (void*)event);
}

static intptr_t w_checkbox_create(float fx, float fy, float size_frac, MonoString* label)
{
        char* s_label = mono_string_to_utf8(label);
        intptr_t _ret = (intptr_t)checkbox_create(fx, fy, size_frac, s_label);
        mono_free(s_label);
        return _ret;
}

static void w_checkbox_destroy(intptr_t checkbox)
{
        checkbox_destroy((checkbox_p)checkbox);
}

static void w_checkbox_set_r2d(intptr_t checkbox, intptr_t r2d)
{
        checkbox_set_r2d((checkbox_p)checkbox, (jr2d_p)r2d);
}

static void w_checkbox_set_position(intptr_t checkbox, int x, int y)
{
        checkbox_set_position((checkbox_p)checkbox, x, y);
}

static void w_checkbox_toggle(intptr_t checkbox)
{
        checkbox_toggle((checkbox_p)checkbox);
}

static bool w_checkbox_is_pressed(intptr_t cb, float x, float y)
{
        bool _ret = checkbox_is_pressed((checkbox_p)cb, x, y);
        return _ret;
}

static void w_checkbox_set_hovered(intptr_t cb, bool v)
{
        checkbox_set_hovered((checkbox_p)cb, v);
}

static void w_checkbox_draw(intptr_t cb, intptr_t r2d, intptr_t font)
{
        checkbox_draw((checkbox_p)cb, (jr2d_p)r2d, (void*)font);
}

static void w_checkbox_process_event(intptr_t cb, intptr_t event)
{
        checkbox_process_event((checkbox_p)cb, (void*)event);
}

static intptr_t w_joystick_create(intptr_t r2d, float cx, float cy, float radius_frac)
{
        intptr_t _ret = (intptr_t)joystick_create((jr2d_p)r2d, cx, cy, radius_frac);
        return _ret;
}

static void w_joystick_destroy(intptr_t joystick)
{
        joystick_destroy((joystick_p)joystick);
}

static void w_joystick_set_textures(intptr_t joystick, MonoString* base_path, MonoString* thumb_path)
{
        char* s_base_path = mono_string_to_utf8(base_path);
        char* s_thumb_path = mono_string_to_utf8(thumb_path);
        joystick_set_textures((joystick_p)joystick, s_base_path, s_thumb_path);
        mono_free(s_base_path);
        mono_free(s_thumb_path);
}

static void w_joystick_set_vector(intptr_t joystick, float dx, float dy)
{
        joystick_set_vector((joystick_p)joystick, dx, dy);
}

static void w_joystick_draw(intptr_t joystick)
{
        joystick_draw((joystick_p)joystick);
}

static void w_joystick_reset(intptr_t joystick)
{
        joystick_reset((joystick_p)joystick);
}

static void w_joystick_set_position(intptr_t joystick, float x, float y)
{
        joystick_set_position((joystick_p)joystick, x, y);
}

static void w_joystick_set_radius(intptr_t joystick, float radius)
{
        joystick_set_radius((joystick_p)joystick, radius);
}

static bool w_joystick_is_dragging(intptr_t joystick)
{
        bool _ret = joystick_is_dragging((joystick_p)joystick);
        return _ret;
}

static void w_joystick_touch_down(intptr_t joystick, float x, float y)
{
        joystick_touch_down((joystick_p)joystick, x, y);
}

static void w_joystick_touch_move(intptr_t joystick, float x, float y)
{
        joystick_touch_move((joystick_p)joystick, x, y);
}

static void w_joystick_touch_up(intptr_t joystick)
{
        joystick_touch_up((joystick_p)joystick);
}

static float w_joystick_get_magnitude(intptr_t joystick)
{
        float _ret = joystick_get_magnitude((joystick_p)joystick);
        return _ret;
}

static void w_joystick_process_event(intptr_t js, intptr_t event)
{
        joystick_process_event((joystick_p)js, (void*)event);
}

static intptr_t w_inputbox_create(intptr_t r2d, float fx, float fy, float fw, float fh, intptr_t font)
{
        intptr_t _ret = (intptr_t)inputbox_create((jr2d_p)r2d, fx, fy, fw, fh, (font_p)font);
        return _ret;
}

static void w_inputbox_destroy(intptr_t ti)
{
        inputbox_destroy((inputbox_p)ti);
}

static void w_inputbox_set_text(intptr_t ti, MonoString* text)
{
        char* s_text = mono_string_to_utf8(text);
        inputbox_set_text((inputbox_p)ti, s_text);
        mono_free(s_text);
}

static void w_inputbox_draw(intptr_t ti)
{
        inputbox_draw((inputbox_p)ti);
}

static bool w_inputbox_is_pressed(intptr_t ti, float x, float y)
{
        bool _ret = inputbox_is_pressed((inputbox_p)ti, x, y);
        return _ret;
}

static bool w_inputbox_is_hovered(intptr_t ti, float x, float y)
{
        bool _ret = inputbox_is_hovered((inputbox_p)ti, x, y);
        return _ret;
}

static void w_inputbox_focus(intptr_t ti)
{
        inputbox_focus((inputbox_p)ti);
}

static void w_inputbox_defocus(intptr_t ti)
{
        inputbox_defocus((inputbox_p)ti);
}

static void w_inputbox_blur(intptr_t ti)
{
        inputbox_blur((inputbox_p)ti);
}

static void w_inputbox_insert(intptr_t ti, MonoString* s, int len)
{
        char* s_s = mono_string_to_utf8(s);
        inputbox_insert((inputbox_p)ti, s_s, len);
        mono_free(s_s);
}

static void w_inputbox_backspace(intptr_t ti)
{
        inputbox_backspace((inputbox_p)ti);
}

static void w_inputbox_delete(intptr_t ti)
{
        inputbox_delete((inputbox_p)ti);
}

static void w_inputbox_cursor_left(intptr_t ti)
{
        inputbox_cursor_left((inputbox_p)ti);
}

static void w_inputbox_cursor_right(intptr_t ti)
{
        inputbox_cursor_right((inputbox_p)ti);
}

static void w_inputbox_cursor_home(intptr_t ti)
{
        inputbox_cursor_home((inputbox_p)ti);
}

static void w_inputbox_cursor_end(intptr_t ti)
{
        inputbox_cursor_end((inputbox_p)ti);
}

static void w_inputbox_select_left(intptr_t ti)
{
        inputbox_select_left((inputbox_p)ti);
}

static void w_inputbox_select_right(intptr_t ti)
{
        inputbox_select_right((inputbox_p)ti);
}

static void w_inputbox_select_home(intptr_t ti)
{
        inputbox_select_home((inputbox_p)ti);
}

static void w_inputbox_select_end(intptr_t ti)
{
        inputbox_select_end((inputbox_p)ti);
}

static void w_inputbox_select_all(intptr_t ti)
{
        inputbox_select_all((inputbox_p)ti);
}

static void w_inputbox_paste(intptr_t ti)
{
        inputbox_paste((inputbox_p)ti);
}

static void w_inputbox_copy(intptr_t ti)
{
        inputbox_copy((inputbox_p)ti);
}

static void w_inputbox_cut(intptr_t ti)
{
        inputbox_cut((inputbox_p)ti);
}

static bool w_inputbox_is_focused(intptr_t ti)
{
        bool _ret = inputbox_is_focused((inputbox_p)ti);
        return _ret;
}

static void w_inputbox_process_event(intptr_t ti, intptr_t event)
{
        inputbox_process_event((inputbox_p)ti, (void*)event);
}

static intptr_t w_slider_create(intptr_t r2d, float fx, float fy, float fw, float fh, float min, float max, float initial)
{
        intptr_t _ret = (intptr_t)slider_create((jr2d_p)r2d, fx, fy, fw, fh, min, max, initial);
        return _ret;
}

static void w_slider_destroy(intptr_t s)
{
        slider_destroy((slider_p)s);
}

static void w_slider_set_value(intptr_t s, float v)
{
        slider_set_value((slider_p)s, v);
}

static float w_slider_get_value(intptr_t s)
{
        float _ret = slider_get_value((slider_p)s);
        return _ret;
}

static void w_slider_set_rect(intptr_t s, float x, float y, float w, float h)
{
        slider_set_rect((slider_p)s, x, y, w, h);
}

static void w_slider_set_range(intptr_t s, float min, float max)
{
        slider_set_range((slider_p)s, min, max);
}

static void w_slider_draw(intptr_t s)
{
        slider_draw((slider_p)s);
}

static bool w_slider_is_pressed(intptr_t s, float x, float y)
{
        bool _ret = slider_is_pressed((slider_p)s, x, y);
        return _ret;
}

static void w_slider_set_pressed(intptr_t s, bool v)
{
        slider_set_pressed((slider_p)s, v);
}

static void w_slider_drag_move(intptr_t s, float x, float y)
{
        slider_drag_move((slider_p)s, x, y);
}

static bool w_slider_is_hovered(intptr_t s, float x, float y)
{
        bool _ret = slider_is_hovered((slider_p)s, x, y);
        return _ret;
}

static void w_slider_set_hovered(intptr_t s, bool v)
{
        slider_set_hovered((slider_p)s, v);
}

static void w_slider_process_event(intptr_t s, intptr_t event)
{
        slider_process_event((slider_p)s, (void*)event);
}

static intptr_t w_popup_create(intptr_t r2d, float fw, float fh)
{
        intptr_t _ret = (intptr_t)popup_create((jr2d_p)r2d, fw, fh);
        return _ret;
}

static void w_popup_destroy(intptr_t p)
{
        popup_destroy((popup_p)p);
}

static void w_popup_set_title(intptr_t p, MonoString* text, int len)
{
        char* s_text = mono_string_to_utf8(text);
        popup_set_title((popup_p)p, s_text, len);
        mono_free(s_text);
}

static void w_popup_set_content(intptr_t p, MonoString* text, int len)
{
        char* s_text = mono_string_to_utf8(text);
        popup_set_content((popup_p)p, s_text, len);
        mono_free(s_text);
}

static void w_popup_set_position(intptr_t p, float x, float y)
{
        popup_set_position((popup_p)p, x, y);
}

static void w_popup_set_visible(intptr_t p, bool v)
{
        popup_set_visible((popup_p)p, v);
}

static void w_popup_set_closeable(intptr_t p, bool v)
{
        popup_set_closeable((popup_p)p, v);
}

static void w_popup_draw(intptr_t p, intptr_t title_font, intptr_t content_font)
{
        popup_draw((popup_p)p, (font_p)title_font, (font_p)content_font);
}

static bool w_popup_is_close_clicked(intptr_t p, float mx, float my)
{
        bool _ret = popup_is_close_clicked((popup_p)p, mx, my);
        return _ret;
}

static bool w_popup_is_title_clicked(intptr_t p, float mx, float my)
{
        bool _ret = popup_is_title_clicked((popup_p)p, mx, my);
        return _ret;
}

static void w_popup_drag_move(intptr_t p, float mx, float my)
{
        popup_drag_move((popup_p)p, mx, my);
}

static bool w_popup_is_inside(intptr_t p, float mx, float my)
{
        bool _ret = popup_is_inside((popup_p)p, mx, my);
        return _ret;
}

static void w_popup_process_event(intptr_t p, intptr_t event)
{
        popup_process_event((popup_p)p, (void*)event);
}

static intptr_t w_tooltip_create(intptr_t r2d, MonoString* text, int len)
{
        char* s_text = mono_string_to_utf8(text);
        intptr_t _ret = (intptr_t)tooltip_create((jr2d_p)r2d, s_text, len);
        mono_free(s_text);
        return _ret;
}

static void w_tooltip_destroy(intptr_t t)
{
        tooltip_destroy((tooltip_p)t);
}

static void w_tooltip_set_text(intptr_t t, MonoString* text, int len)
{
        char* s_text = mono_string_to_utf8(text);
        tooltip_set_text((tooltip_p)t, s_text, len);
        mono_free(s_text);
}

static void w_tooltip_set_position(intptr_t t, float x, float y)
{
        tooltip_set_position((tooltip_p)t, x, y);
}

static void w_tooltip_set_visible(intptr_t t, bool v)
{
        tooltip_set_visible((tooltip_p)t, v);
}

static void w_tooltip_draw(intptr_t t, intptr_t font)
{
        tooltip_draw((tooltip_p)t, (font_p)font);
}

static void w_tooltip_process_event(intptr_t t, intptr_t event)
{
        tooltip_process_event((tooltip_p)t, (void*)event);
}

static intptr_t w_jui_ctx_create(intptr_t r2d, intptr_t font)
{
        intptr_t _ret = (intptr_t)jui_ctx_create((jr2d_p)r2d, (font_p)font);
        return _ret;
}

static void w_jui_ctx_destroy(intptr_t ctx)
{
        jui_ctx_destroy((jui_ctx_p)ctx);
}

static void w_jui_begin(intptr_t ctx)
{
        jui_begin((jui_ctx_p)ctx);
}

static void w_jui_end(intptr_t ctx)
{
        jui_end((jui_ctx_p)ctx);
}

static void w_jui_input_motion(intptr_t ctx, float win_x, float win_y)
{
        jui_input_motion((jui_ctx_p)ctx, win_x, win_y);
}

static void w_jui_input_down(intptr_t ctx, int button)
{
        jui_input_down((jui_ctx_p)ctx, button);
}

static void w_jui_input_up(intptr_t ctx, int button)
{
        jui_input_up((jui_ctx_p)ctx, button);
}

static void w_jui_input_wheel(intptr_t ctx, float dy)
{
        jui_input_wheel((jui_ctx_p)ctx, dy);
}

static void w_jui_input_key(intptr_t ctx, bool shift, bool ctrl)
{
        jui_input_key((jui_ctx_p)ctx, shift, ctrl);
}

static bool w_jui_is_down(intptr_t ctx)
{
        bool _ret = jui_is_down((jui_ctx_p)ctx);
        return _ret;
}

static bool w_jui_is_pressed(intptr_t ctx)
{
        bool _ret = jui_is_pressed((jui_ctx_p)ctx);
        return _ret;
}

static bool w_jui_is_released(intptr_t ctx)
{
        bool _ret = jui_is_released((jui_ctx_p)ctx);
        return _ret;
}

static float w_jui_take_wheel(intptr_t ctx)
{
        float _ret = jui_take_wheel((jui_ctx_p)ctx);
        return _ret;
}

static bool w_jui_is_shift(intptr_t ctx)
{
        bool _ret = jui_is_shift((jui_ctx_p)ctx);
        return _ret;
}

static bool w_jui_is_ctrl(intptr_t ctx)
{
        bool _ret = jui_is_ctrl((jui_ctx_p)ctx);
        return _ret;
}

static void w_jui_pop_clip(intptr_t ctx)
{
        jui_pop_clip((jui_ctx_p)ctx);
}

static void w_jui_reset_clip(intptr_t ctx)
{
        jui_reset_clip((jui_ctx_p)ctx);
}

static void w_jui_panel_end(intptr_t ctx)
{
        jui_panel_end((jui_ctx_p)ctx);
}

static void w_jui_scroll_end(intptr_t ctx)
{
        jui_scroll_end((jui_ctx_p)ctx);
}

static void w_jui_scroll_set_offset(intptr_t ctx, int id, float off, float content_h, float view_h)
{
        jui_scroll_set_offset((jui_ctx_p)ctx, id, off, content_h, view_h);
}

static intptr_t w_jtilemap_load_file_json(MonoString* filename)
{
        char* s_filename = mono_string_to_utf8(filename);
        intptr_t _ret = (intptr_t)jtilemap_load_file_json(s_filename);
        mono_free(s_filename);
        return _ret;
}

static void w_jtilemap_destroy(intptr_t tm)
{
        jtilemap_destroy((jtilemap_p)tm);
}

static int w_jtilemap_get_width(intptr_t tm)
{
        int _ret = jtilemap_get_width((jtilemap_p)tm);
        return _ret;
}

static int w_jtilemap_get_height(intptr_t tm)
{
        int _ret = jtilemap_get_height((jtilemap_p)tm);
        return _ret;
}

static int w_jtilemap_get_tilewidth(intptr_t tm)
{
        int _ret = jtilemap_get_tilewidth((jtilemap_p)tm);
        return _ret;
}

static int w_jtilemap_get_tileheight(intptr_t tm)
{
        int _ret = jtilemap_get_tileheight((jtilemap_p)tm);
        return _ret;
}

static int w_jtilemap_get_anim_tileid(intptr_t tm, int gid, uint32_t time_ms)
{
        int _ret = jtilemap_get_anim_tileid((jtilemap_p)tm, gid, time_ms);
        return _ret;
}

static intptr_t w_jtilemap_find_tile_layer(intptr_t tm, MonoString* name)
{
        char* s_name = mono_string_to_utf8(name);
        intptr_t _ret = (intptr_t)jtilemap_find_tile_layer((jtilemap_p)tm, s_name);
        mono_free(s_name);
        return _ret;
}

static intptr_t w_jtilemap_find_object_layer(intptr_t tm, MonoString* name)
{
        char* s_name = mono_string_to_utf8(name);
        intptr_t _ret = (intptr_t)jtilemap_find_object_layer((jtilemap_p)tm, s_name);
        mono_free(s_name);
        return _ret;
}

static int w_jtilemap_get_tile(intptr_t layer, int tx, int ty)
{
        int _ret = jtilemap_get_tile((jtilemap_tile_layer_p)layer, tx, ty);
        return _ret;
}

static void w_jtilemap_render_all(intptr_t r, intptr_t tm, float camera_x, float camera_y, uint32_t time_ms)
{
        jtilemap_render_all((jtilemap_render_p)r, (jtilemap_p)tm, camera_x, camera_y, time_ms);
}

static void w_jtilemap_render_tiles(intptr_t r, intptr_t tm, float camera_x, float camera_y, uint32_t time_ms)
{
        jtilemap_render_tiles((jtilemap_render_p)r, (jtilemap_p)tm, camera_x, camera_y, time_ms);
}

static void w_jtilemap_render_set_tile_px(intptr_t r, float px)
{
        jtilemap_render_set_tile_px((jtilemap_render_p)r, px);
}

static bool w_jtilemap_render_layer(intptr_t r, intptr_t tm, MonoString* layer_name, float camera_x, float camera_y, uint32_t time_ms)
{
        char* s_layer_name = mono_string_to_utf8(layer_name);
        bool _ret = jtilemap_render_layer((jtilemap_render_p)r, (jtilemap_p)tm, s_layer_name, camera_x, camera_y, time_ms);
        mono_free(s_layer_name);
        return _ret;
}

static void w_jtilemap_render_destroy(intptr_t r)
{
        jtilemap_render_destroy((jtilemap_render_p)r);
}

static intptr_t w_kcpserver_create(MonoString* ip, int port)
{
        char* s_ip = mono_string_to_utf8(ip);
        intptr_t _ret = (intptr_t)kcpserver_create(s_ip, port);
        mono_free(s_ip);
        return _ret;
}

static int w_kcpserver_destroy(intptr_t ks)
{
        int _ret = kcpserver_destroy((kcpserver_p)ks);
        return _ret;
}

static void w_kcpserver_send(intptr_t ks, int conv, MonoString* data, int len)
{
        char* s_data = mono_string_to_utf8(data);
        kcpserver_send((kcpserver_p)ks, conv, s_data, len);
        mono_free(s_data);
}

static void w_kcpserver_broadcast(intptr_t ks, MonoString* data, int len)
{
        char* s_data = mono_string_to_utf8(data);
        kcpserver_broadcast((kcpserver_p)ks, s_data, len);
        mono_free(s_data);
}

static void w_kcpserver_offline(intptr_t ks, int conv)
{
        kcpserver_offline((kcpserver_p)ks, conv);
}

static void w_kcpserver_update(intptr_t ks)
{
        kcpserver_update((kcpserver_p)ks);
}

static int w_kcpserver_connection_count(intptr_t ks)
{
        int _ret = kcpserver_connection_count((kcpserver_p)ks);
        return _ret;
}

static bool w_kcpserver_poll_message(intptr_t ks, intptr_t msg)
{
        bool _ret = kcpserver_poll_message((kcpserver_p)ks, (net_message_p)msg);
        return _ret;
}

static intptr_t w_kcpclient_create(MonoString* ip, int port)
{
        char* s_ip = mono_string_to_utf8(ip);
        intptr_t _ret = (intptr_t)kcpclient_create(s_ip, port);
        mono_free(s_ip);
        return _ret;
}

static void w_kcpclient_destroy(intptr_t kc)
{
        kcpclient_destroy((kcpclient_p)kc);
}

static int w_kcpclient_send(intptr_t kc, MonoString* data, int len)
{
        char* s_data = mono_string_to_utf8(data);
        int _ret = kcpclient_send((kcpclient_p)kc, s_data, len);
        mono_free(s_data);
        return _ret;
}

static void w_kcpclient_update(intptr_t kc)
{
        kcpclient_update((kcpclient_p)kc);
}

static bool w_kcpclient_poll_message(intptr_t kc, intptr_t msg)
{
        bool _ret = kcpclient_poll_message((kcpclient_p)kc, (net_message_p)msg);
        return _ret;
}

static intptr_t w_tcpserver_create(MonoString* ip, int port)
{
        char* s_ip = mono_string_to_utf8(ip);
        intptr_t _ret = (intptr_t)tcpserver_create(s_ip, port);
        mono_free(s_ip);
        return _ret;
}

static int w_tcpserver_destroy(intptr_t tcpserver)
{
        int _ret = tcpserver_destroy((tcpserver_p)tcpserver);
        return _ret;
}

static void w_tcpserver_send(intptr_t tcpserver, int conv, MonoString* data, int len)
{
        char* s_data = mono_string_to_utf8(data);
        tcpserver_send((tcpserver_p)tcpserver, conv, s_data, len);
        mono_free(s_data);
}

static void w_tcpserver_broadcast(intptr_t tcpserver, MonoString* data, int len)
{
        char* s_data = mono_string_to_utf8(data);
        tcpserver_broadcast((tcpserver_p)tcpserver, s_data, len);
        mono_free(s_data);
}

static void w_tcpserver_offline(intptr_t tcpserver, int conv)
{
        tcpserver_offline((tcpserver_p)tcpserver, conv);
}

static void w_tcpserver_update(intptr_t tcpserver)
{
        tcpserver_update((tcpserver_p)tcpserver);
}

static int w_tcpserver_connection_count(intptr_t tcpserver)
{
        int _ret = tcpserver_connection_count((tcpserver_p)tcpserver);
        return _ret;
}

static bool w_tcpserver_poll_message(intptr_t tcpserver, intptr_t msg)
{
        bool _ret = tcpserver_poll_message((tcpserver_p)tcpserver, (net_message_p)msg);
        return _ret;
}

static intptr_t w_tcpclient_create(MonoString* ip, int port)
{
        char* s_ip = mono_string_to_utf8(ip);
        intptr_t _ret = (intptr_t)tcpclient_create(s_ip, port);
        mono_free(s_ip);
        return _ret;
}

static void w_tcpclient_destroy(intptr_t tcpclient)
{
        tcpclient_destroy((tcpclient_p)tcpclient);
}

static int w_tcpclient_send(intptr_t tcpclient, MonoString* data, int len)
{
        char* s_data = mono_string_to_utf8(data);
        int _ret = tcpclient_send((tcpclient_p)tcpclient, s_data, len);
        mono_free(s_data);
        return _ret;
}

static void w_tcpclient_update(intptr_t tcpclient)
{
        tcpclient_update((tcpclient_p)tcpclient);
}

static bool w_tcpclient_poll_message(intptr_t tcpclient, intptr_t msg)
{
        bool _ret = tcpclient_poll_message((tcpclient_p)tcpclient, (net_message_p)msg);
        return _ret;
}

static intptr_t w_wsnetserver_create(MonoString* ip, int port)
{
        char* s_ip = mono_string_to_utf8(ip);
        intptr_t _ret = (intptr_t)wsnetserver_create(s_ip, port);
        mono_free(s_ip);
        return _ret;
}

static int w_wsnetserver_destroy(intptr_t ws)
{
        int _ret = wsnetserver_destroy((wsnetserver_p)ws);
        return _ret;
}

static void w_wsnetserver_send(intptr_t ws, int conv, MonoString* data, int len)
{
        char* s_data = mono_string_to_utf8(data);
        wsnetserver_send((wsnetserver_p)ws, conv, s_data, len);
        mono_free(s_data);
}

static void w_wsnetserver_broadcast(intptr_t ws, MonoString* data, int len)
{
        char* s_data = mono_string_to_utf8(data);
        wsnetserver_broadcast((wsnetserver_p)ws, s_data, len);
        mono_free(s_data);
}

static void w_wsnetserver_offline(intptr_t ws, int conv)
{
        wsnetserver_offline((wsnetserver_p)ws, conv);
}

static void w_wsnetserver_update(intptr_t ws)
{
        wsnetserver_update((wsnetserver_p)ws);
}

static int w_wsnetserver_connection_count(intptr_t ws)
{
        int _ret = wsnetserver_connection_count((wsnetserver_p)ws);
        return _ret;
}

static bool w_wsnetserver_poll_message(intptr_t ws, intptr_t msg)
{
        bool _ret = wsnetserver_poll_message((wsnetserver_p)ws, (net_message_p)msg);
        return _ret;
}

static intptr_t w_wsnetclient_create(MonoString* url)
{
        char* s_url = mono_string_to_utf8(url);
        intptr_t _ret = (intptr_t)wsnetclient_create(s_url);
        mono_free(s_url);
        return _ret;
}

static void w_wsnetclient_destroy(intptr_t wc)
{
        wsnetclient_destroy((wsnetclient_p)wc);
}

static int w_wsnetclient_send(intptr_t wc, MonoString* data, int len)
{
        char* s_data = mono_string_to_utf8(data);
        int _ret = wsnetclient_send((wsnetclient_p)wc, s_data, len);
        mono_free(s_data);
        return _ret;
}

static void w_wsnetclient_update(intptr_t wc)
{
        wsnetclient_update((wsnetclient_p)wc);
}

static bool w_wsnetclient_poll_message(intptr_t wc, intptr_t msg)
{
        bool _ret = wsnetclient_poll_message((wsnetclient_p)wc, (net_message_p)msg);
        return _ret;
}

static void w_netclient_destroy(intptr_t nc)
{
        netclient_destroy((netclient_p)nc);
}

static int w_netclient_send(intptr_t nc, MonoString* data, int len)
{
        char* s_data = mono_string_to_utf8(data);
        int _ret = netclient_send((netclient_p)nc, s_data, len);
        mono_free(s_data);
        return _ret;
}

static void w_netclient_update(intptr_t nc)
{
        netclient_update((netclient_p)nc);
}

static bool w_netclient_poll_message(intptr_t nc, intptr_t msg)
{
        bool _ret = netclient_poll_message((netclient_p)nc, (net_message_p)msg);
        return _ret;
}

static void w_netserver_destroy(intptr_t ns)
{
        netserver_destroy((netserver_p)ns);
}

static void w_netserver_send(intptr_t ns, int conv, MonoString* data, int len)
{
        char* s_data = mono_string_to_utf8(data);
        netserver_send((netserver_p)ns, conv, s_data, len);
        mono_free(s_data);
}

static void w_netserver_broadcast(intptr_t ns, MonoString* data, int len)
{
        char* s_data = mono_string_to_utf8(data);
        netserver_broadcast((netserver_p)ns, s_data, len);
        mono_free(s_data);
}

static void w_netserver_offline(intptr_t ns, int conv)
{
        netserver_offline((netserver_p)ns, conv);
}

static void w_netserver_update(intptr_t ns)
{
        netserver_update((netserver_p)ns);
}

static int w_netserver_connection_count(intptr_t ns)
{
        int _ret = netserver_connection_count((netserver_p)ns);
        return _ret;
}

static bool w_netserver_poll_message(intptr_t ns, intptr_t msg)
{
        bool _ret = netserver_poll_message((netserver_p)ns, (net_message_p)msg);
        return _ret;
}

static void w_netmessage_free_data(intptr_t msg)
{
        netmessage_free_data((net_message_p)msg);
}

static intptr_t w_scene_node_create(void)
{
        intptr_t _ret = (intptr_t)scene_node_create();
        return _ret;
}

static void w_scene_node_destroy(intptr_t node)
{
        scene_node_destroy((scene_node_p)node);
}

static void w_scene_node_add_child(intptr_t parent, intptr_t child)
{
        scene_node_add_child((scene_node_p)parent, (scene_node_p)child);
}

static void w_scene_node_remove_child(intptr_t parent, intptr_t child)
{
        scene_node_remove_child((scene_node_p)parent, (scene_node_p)child);
}

static intptr_t w_scene_node_get_parent(intptr_t node)
{
        intptr_t _ret = (intptr_t)scene_node_get_parent((scene_node_p)node);
        return _ret;
}

static intptr_t w_scene_node_get_first_child(intptr_t node)
{
        intptr_t _ret = (intptr_t)scene_node_get_first_child((scene_node_p)node);
        return _ret;
}

static intptr_t w_scene_node_get_next_sibling(intptr_t node)
{
        intptr_t _ret = (intptr_t)scene_node_get_next_sibling((scene_node_p)node);
        return _ret;
}

static int w_scene_node_get_child_count(intptr_t node)
{
        int _ret = scene_node_get_child_count((scene_node_p)node);
        return _ret;
}

static void w_scene_node_set_position(intptr_t node, float x, float y)
{
        scene_node_set_position((scene_node_p)node, x, y);
}

static void w_scene_node_set_world_position(intptr_t node, float x, float y)
{
        scene_node_set_world_position((scene_node_p)node, x, y);
}

static void w_scene_node_set_rotation(intptr_t node, float radians)
{
        scene_node_set_rotation((scene_node_p)node, radians);
}

static float w_scene_node_get_rotation(intptr_t node)
{
        float _ret = scene_node_get_rotation((scene_node_p)node);
        return _ret;
}

static void w_scene_node_set_scale(intptr_t node, float scale_x, float scale_y)
{
        scene_node_set_scale((scene_node_p)node, scale_x, scale_y);
}

static void w_scene_node_set_zorder(intptr_t node, int zorder)
{
        scene_node_set_zorder((scene_node_p)node, zorder);
}

static int w_scene_node_get_zorder(intptr_t node)
{
        int _ret = scene_node_get_zorder((scene_node_p)node);
        return _ret;
}

static void w_scene_node_set_userdata(intptr_t node, intptr_t userdata)
{
        scene_node_set_userdata((scene_node_p)node, (void*)userdata);
}

static intptr_t w_scene_node_get_userdata(intptr_t node)
{
        intptr_t _ret = (intptr_t)scene_node_get_userdata((scene_node_p)node);
        return _ret;
}

static void w_scene_node_set_name(intptr_t node, MonoString* name)
{
        char* s_name = mono_string_to_utf8(name);
        scene_node_set_name((scene_node_p)node, s_name);
        mono_free(s_name);
}

static void w_scene_node_set_tag(intptr_t node, MonoString* tag)
{
        char* s_tag = mono_string_to_utf8(tag);
        scene_node_set_tag((scene_node_p)node, s_tag);
        mono_free(s_tag);
}

static intptr_t w_scene_find_node_by_name(intptr_t root, MonoString* name)
{
        char* s_name = mono_string_to_utf8(name);
        intptr_t _ret = (intptr_t)scene_find_node_by_name((scene_node_p)root, s_name);
        mono_free(s_name);
        return _ret;
}

static intptr_t w_scene_find_node_by_name_deep(intptr_t scene, MonoString* name)
{
        char* s_name = mono_string_to_utf8(name);
        intptr_t _ret = (intptr_t)scene_find_node_by_name_deep((scene_p)scene, s_name);
        mono_free(s_name);
        return _ret;
}

static void w_scene_node_handle_event(intptr_t node, intptr_t e)
{
        scene_node_handle_event((scene_node_p)node, (void*)e);
}

static void w_scene_node_update(intptr_t node, float delta_time)
{
        scene_node_update((scene_node_p)node, delta_time);
}

static void w_scene_node_render(intptr_t node, intptr_t arg)
{
        scene_node_render((scene_node_p)node, (void*)arg);
}

static intptr_t w_scene_create(MonoString* name)
{
        char* s_name = mono_string_to_utf8(name);
        intptr_t _ret = (intptr_t)scene_create(s_name);
        mono_free(s_name);
        return _ret;
}

static void w_scene_destroy(intptr_t scene)
{
        scene_destroy((scene_p)scene);
}

static void w_scene_add_root_node(intptr_t scene, intptr_t root)
{
        scene_add_root_node((scene_p)scene, (scene_node_p)root);
}

static void w_scene_remove_root_node(intptr_t scene, intptr_t root)
{
        scene_remove_root_node((scene_p)scene, (scene_node_p)root);
}

static int w_scene_get_root_count(intptr_t scene)
{
        int _ret = scene_get_root_count((scene_p)scene);
        return _ret;
}

static intptr_t w_scene_get_root_at(intptr_t scene, int index)
{
        intptr_t _ret = (intptr_t)scene_get_root_at((scene_p)scene, index);
        return _ret;
}

static void w_scene_update(intptr_t scene, float delta_time)
{
        scene_update((scene_p)scene, delta_time);
}

static void w_scene_render(intptr_t scene, intptr_t arg)
{
        scene_render((scene_p)scene, (void*)arg);
}

static void w_scene_handle_event(intptr_t scene, intptr_t e)
{
        scene_handle_event((scene_p)scene, (void*)e);
}

static void w_scene_set_popup_node(intptr_t scene, intptr_t node)
{
        scene_set_popup_node((scene_p)scene, (scene_node_p)node);
}

static intptr_t w_scene_get_popup_node(intptr_t scene)
{
        intptr_t _ret = (intptr_t)scene_get_popup_node((scene_p)scene);
        return _ret;
}

static void w_scene_set_userdata(intptr_t scene, intptr_t ud)
{
        scene_set_userdata((scene_p)scene, (void*)ud);
}

static intptr_t w_scene_get_userdata(intptr_t scene)
{
        intptr_t _ret = (intptr_t)scene_get_userdata((scene_p)scene);
        return _ret;
}

static intptr_t w_scene_manager_create(void)
{
        intptr_t _ret = (intptr_t)scene_manager_create();
        return _ret;
}

static void w_scene_manager_destroy(intptr_t mgr)
{
        scene_manager_destroy((scene_manager_p)mgr);
}

static void w_scene_manager_push(intptr_t mgr, intptr_t scene)
{
        scene_manager_push((scene_manager_p)mgr, (scene_p)scene);
}

static void w_scene_manager_replace(intptr_t mgr, intptr_t scene)
{
        scene_manager_replace((scene_manager_p)mgr, (scene_p)scene);
}

static void w_scene_manager_pop(intptr_t mgr)
{
        scene_manager_pop((scene_manager_p)mgr);
}

static void w_scene_manager_update(intptr_t mgr, float delta_time)
{
        scene_manager_update((scene_manager_p)mgr, delta_time);
}

static void w_scene_manager_render(intptr_t mgr, intptr_t arg)
{
        scene_manager_render((scene_manager_p)mgr, (void*)arg);
}

static void w_scene_manager_handle_event(intptr_t mgr, intptr_t e)
{
        scene_manager_handle_event((scene_manager_p)mgr, (void*)e);
}

static intptr_t w_scene_manager_get_current(intptr_t mgr)
{
        intptr_t _ret = (intptr_t)scene_manager_get_current((scene_manager_p)mgr);
        return _ret;
}

static int w_scene_manager_get_count(intptr_t mgr)
{
        int _ret = scene_manager_get_count((scene_manager_p)mgr);
        return _ret;
}

static void w_jparticle_destroy(intptr_t p)
{
        jparticle_destroy((jparticle_p)p);
}

static void w_jparticle_set_position(intptr_t p, float x, float y)
{
        jparticle_set_position((jparticle_p)p, x, y);
}

static void w_jparticle_emit(intptr_t p)
{
        jparticle_emit((jparticle_p)p);
}

static void w_jparticle_clear(intptr_t p)
{
        jparticle_clear((jparticle_p)p);
}

static void w_jparticle_update(intptr_t p, float dt)
{
        jparticle_update((jparticle_p)p, dt);
}

static void w_jparticle_render(intptr_t p, intptr_t r2d)
{
        jparticle_render((jparticle_p)p, (jr2d_p)r2d);
}

static int w_jparticle_count(intptr_t p)
{
        int _ret = jparticle_count((jparticle_p)p);
        return _ret;
}

static bool w_jparticle_is_active(intptr_t p)
{
        bool _ret = jparticle_is_active((jparticle_p)p);
        return _ret;
}

static intptr_t w_jlight_sys_create(int width, int height)
{
        intptr_t _ret = (intptr_t)jlight_sys_create(width, height);
        return _ret;
}

static void w_jlight_sys_destroy(intptr_t sys)
{
        jlight_sys_destroy((jlight_sys_p)sys);
}

static void w_jlight_sys_resize(intptr_t sys, int width, int height)
{
        jlight_sys_resize((jlight_sys_p)sys, width, height);
}

static void w_jlight_remove(intptr_t sys, int id)
{
        jlight_remove((jlight_sys_p)sys, id);
}

static void w_jlight_clear(intptr_t sys)
{
        jlight_clear((jlight_sys_p)sys);
}

static int w_jlight_add_occluder(intptr_t sys, float x1, float y1, float x2, float y2)
{
        int _ret = jlight_add_occluder((jlight_sys_p)sys, x1, y1, x2, y2);
        return _ret;
}

static void w_jlight_clear_occluders(intptr_t sys)
{
        jlight_clear_occluders((jlight_sys_p)sys);
}

static void w_jlight_render(intptr_t sys, intptr_t r2d)
{
        jlight_render((jlight_sys_p)sys, (jr2d_p)r2d);
}

static intptr_t w_jecs_create(void)
{
        intptr_t _ret = (intptr_t)jecs_create();
        return _ret;
}

static void w_jecs_destroy(intptr_t world)
{
        jecs_destroy((jecs_world_p)world);
}

static void w_jecs_process(intptr_t world, float dt)
{
        jecs_process((jecs_world_p)world, dt);
}

static void w_jecs_define(intptr_t world, MonoString* name, size_t size)
{
        char* s_name = mono_string_to_utf8(name);
        jecs_define((jecs_world_p)world, s_name, size);
        mono_free(s_name);
}

static uint32_t w_audio_open_device(void)
{
        uint32_t _ret = audio_open_device();
        return _ret;
}

static void w_audio_close_device(uint32_t device_id)
{
        audio_close_device(device_id);
}

static bool w_audio_create_wav(MonoString* filepath, uint32_t device_id)
{
        char* s_filepath = mono_string_to_utf8(filepath);
        bool _ret = audio_create_wav(s_filepath, device_id);
        mono_free(s_filepath);
        return _ret;
}

static bool w_audio_create_mp3(MonoString* filepath, uint32_t device_id)
{
        char* s_filepath = mono_string_to_utf8(filepath);
        bool _ret = audio_create_mp3(s_filepath, device_id);
        mono_free(s_filepath);
        return _ret;
}

static bool w_audio_create_flac(MonoString* filepath, uint32_t device_id)
{
        char* s_filepath = mono_string_to_utf8(filepath);
        bool _ret = audio_create_flac(s_filepath, device_id);
        mono_free(s_filepath);
        return _ret;
}

static bool w_audio_create_ogg(MonoString* filepath, uint32_t device_id)
{
        char* s_filepath = mono_string_to_utf8(filepath);
        bool _ret = audio_create_ogg(s_filepath, device_id);
        mono_free(s_filepath);
        return _ret;
}

static intptr_t w_audio_shot_create(MonoString* wav_path, uint32_t device_id)
{
        char* s_wav_path = mono_string_to_utf8(wav_path);
        intptr_t _ret = (intptr_t)audio_shot_create(s_wav_path, device_id);
        mono_free(s_wav_path);
        return _ret;
}

static intptr_t w_audio_shot_create_mp3(MonoString* path, uint32_t device_id)
{
        char* s_path = mono_string_to_utf8(path);
        intptr_t _ret = (intptr_t)audio_shot_create_mp3(s_path, device_id);
        mono_free(s_path);
        return _ret;
}

static intptr_t w_audio_shot_create_flac(MonoString* path, uint32_t device_id)
{
        char* s_path = mono_string_to_utf8(path);
        intptr_t _ret = (intptr_t)audio_shot_create_flac(s_path, device_id);
        mono_free(s_path);
        return _ret;
}

static intptr_t w_audio_shot_create_ogg(MonoString* path, uint32_t device_id)
{
        char* s_path = mono_string_to_utf8(path);
        intptr_t _ret = (intptr_t)audio_shot_create_ogg(s_path, device_id);
        mono_free(s_path);
        return _ret;
}

static void w_audio_shot_play(intptr_t shot)
{
        audio_shot_play((audio_shot_p)shot);
}

static void w_audio_shot_set_gain(intptr_t shot, float gain)
{
        audio_shot_set_gain((audio_shot_p)shot, gain);
}

static void w_audio_shot_destroy(intptr_t shot)
{
        audio_shot_destroy((audio_shot_p)shot);
}

static intptr_t w_audio_bgm_create(MonoString* wav_path, uint32_t device_id)
{
        char* s_wav_path = mono_string_to_utf8(wav_path);
        intptr_t _ret = (intptr_t)audio_bgm_create(s_wav_path, device_id);
        mono_free(s_wav_path);
        return _ret;
}

static intptr_t w_audio_bgm_create_mp3(MonoString* path, uint32_t device_id)
{
        char* s_path = mono_string_to_utf8(path);
        intptr_t _ret = (intptr_t)audio_bgm_create_mp3(s_path, device_id);
        mono_free(s_path);
        return _ret;
}

static intptr_t w_audio_bgm_create_flac(MonoString* path, uint32_t device_id)
{
        char* s_path = mono_string_to_utf8(path);
        intptr_t _ret = (intptr_t)audio_bgm_create_flac(s_path, device_id);
        mono_free(s_path);
        return _ret;
}

static intptr_t w_audio_bgm_create_ogg(MonoString* path, uint32_t device_id)
{
        char* s_path = mono_string_to_utf8(path);
        intptr_t _ret = (intptr_t)audio_bgm_create_ogg(s_path, device_id);
        mono_free(s_path);
        return _ret;
}

static void w_audio_bgm_stop(intptr_t bgm)
{
        audio_bgm_stop((audio_bgm_p)bgm);
}

static void w_audio_bgm_set_gain(intptr_t bgm, float gain)
{
        audio_bgm_set_gain((audio_bgm_p)bgm, gain);
}

static void w_audio_bgm_destroy(intptr_t bgm)
{
        audio_bgm_destroy((audio_bgm_p)bgm);
}

void csopen_generated(void)
{
        csx_register_internal_call("Joy.Lcg::lcg_random_create", (const void*)w_lcg_random_create);
        csx_register_internal_call("Joy.Lcg::lcg_random_destroy", (const void*)w_lcg_random_destroy);
        csx_register_internal_call("Joy.Lcg::lcg_random_next", (const void*)w_lcg_random_next);
        csx_register_internal_call("Joy.Lcg::lcg_random_set_state", (const void*)w_lcg_random_set_state);
        csx_register_internal_call("Joy.Jpm::jpm_config_add_spawn", (const void*)w_jpm_config_add_spawn);
        csx_register_internal_call("Joy.Jpm::jpm_wave_seed", (const void*)w_jpm_wave_seed);
        csx_register_internal_call("Joy.Jtimer::jtimer_destroy", (const void*)w_jtimer_destroy);
        csx_register_internal_call("Joy.Jtimer::jtimer_trigger", (const void*)w_jtimer_trigger);
        csx_register_internal_call("Joy.Jtimer::jtimer_set_interval", (const void*)w_jtimer_set_interval);
        csx_register_internal_call("Joy.Jtimer::jtimer_set_active", (const void*)w_jtimer_set_active);
        csx_register_internal_call("Joy.Jtimer::jtimer_reset", (const void*)w_jtimer_reset);
        csx_register_internal_call("Joy.Jtimer::jtimer_get_elapsed", (const void*)w_jtimer_get_elapsed);
        csx_register_internal_call("Joy.Init::init_env", (const void*)w_init_env);
        csx_register_internal_call("Joy.Quit::quit_env", (const void*)w_quit_env);
        csx_register_internal_call("Joy.Get::get_ticks", (const void*)w_get_ticks);
        csx_register_internal_call("Joy.Get::get_mouse_button", (const void*)w_get_mouse_button);
        csx_register_internal_call("Joy.Create::create_window", (const void*)w_create_window);
        csx_register_internal_call("Joy.Destroy::destroy_window", (const void*)w_destroy_window);
        csx_register_internal_call("Joy.Get::get_raw_window", (const void*)w_get_raw_window);
        csx_register_internal_call("Joy.Window::window_set_fullscreen", (const void*)w_window_set_fullscreen);
        csx_register_internal_call("Joy.Window::window_get_fullscreen", (const void*)w_window_get_fullscreen);
        csx_register_internal_call("Joy.Window::window_set_icon", (const void*)w_window_set_icon);
        csx_register_internal_call("Joy.Get::get_event_type", (const void*)w_get_event_type);
        csx_register_internal_call("Joy.Get::get_event_code", (const void*)w_get_event_code);
        csx_register_internal_call("Joy.Is::is_user_event", (const void*)w_is_user_event);
        csx_register_internal_call("Joy.Push::push_user_event", (const void*)w_push_user_event);
        csx_register_internal_call("Joy.Push::push_quit_event", (const void*)w_push_quit_event);
        csx_register_internal_call("Joy.Should::should_close", (const void*)w_should_close);
        csx_register_internal_call("Joy.Log::log_title", (const void*)w_log_title);
        csx_register_internal_call("Joy.Env::env_create", (const void*)w_env_create);
        csx_register_internal_call("Joy.Env::env_set", (const void*)w_env_set);
        csx_register_internal_call("Joy.Env::env_destroy", (const void*)w_env_destroy);
        csx_register_internal_call("Joy.Simple::simple_fps_create", (const void*)w_simple_fps_create);
        csx_register_internal_call("Joy.Simple::simple_fps_destory", (const void*)w_simple_fps_destory);
        csx_register_internal_call("Joy.Simple::simple_fps_update", (const void*)w_simple_fps_update);
        csx_register_internal_call("Joy.Simple::simple_fps_value", (const void*)w_simple_fps_value);
        csx_register_internal_call("Joy.Game::game_timer_init", (const void*)w_game_timer_init);
        csx_register_internal_call("Joy.Game::game_timer_update", (const void*)w_game_timer_update);
        csx_register_internal_call("Joy.Game::game_timer_get_delta_time", (const void*)w_game_timer_get_delta_time);
        csx_register_internal_call("Joy.Game::game_timer_get_unscaled_delta_time", (const void*)w_game_timer_get_unscaled_delta_time);
        csx_register_internal_call("Joy.Game::game_timer_set_time_scale", (const void*)w_game_timer_set_time_scale);
        csx_register_internal_call("Joy.Game::game_timer_get_time_scale", (const void*)w_game_timer_get_time_scale);
        csx_register_internal_call("Joy.Game::game_timer_set_target_fps", (const void*)w_game_timer_set_target_fps);
        csx_register_internal_call("Joy.Game::game_timer_get_target_fps", (const void*)w_game_timer_get_target_fps);
        csx_register_internal_call("Joy.Set::set_clipboard_text", (const void*)w_set_clipboard_text);
        csx_register_internal_call("Joy.Sys::sys_init_netenv", (const void*)w_sys_init_netenv);
        csx_register_internal_call("Joy.Sys::sys_release_netenv", (const void*)w_sys_release_netenv);
        csx_register_internal_call("Joy.Sys::sys_anyaddr", (const void*)w_sys_anyaddr);
        csx_register_internal_call("Joy.Sys::sys_closesocket", (const void*)w_sys_closesocket);
        csx_register_internal_call("Joy.Sys::sys_set_sock_sndtimeo", (const void*)w_sys_set_sock_sndtimeo);
        csx_register_internal_call("Joy.Sys::sys_set_sock_rcvtimeo", (const void*)w_sys_set_sock_rcvtimeo);
        csx_register_internal_call("Joy.Sys::sys_set_sock_accpettimeo", (const void*)w_sys_set_sock_accpettimeo);
        csx_register_internal_call("Joy.Sys::sys_set_sock_broadcast", (const void*)w_sys_set_sock_broadcast);
        csx_register_internal_call("Joy.Sys::sys_set_sock_reuseaddr", (const void*)w_sys_set_sock_reuseaddr);
        csx_register_internal_call("Joy.Sys::sys_tcp", (const void*)w_sys_tcp);
        csx_register_internal_call("Joy.Sys::sys_udp", (const void*)w_sys_udp);
        csx_register_internal_call("Joy.Sys::sys_bind", (const void*)w_sys_bind);
        csx_register_internal_call("Joy.Sys::sys_connect", (const void*)w_sys_connect);
        csx_register_internal_call("Joy.Sys::sys_listen", (const void*)w_sys_listen);
        csx_register_internal_call("Joy.Sys::sys_send", (const void*)w_sys_send);
        csx_register_internal_call("Joy.Sys::sys_sendto", (const void*)w_sys_sendto);
        csx_register_internal_call("Joy.Sys::sys_current_time", (const void*)w_sys_current_time);
        csx_register_internal_call("Joy.Sys::sys_sleep", (const void*)w_sys_sleep);
        csx_register_internal_call("Joy.Sys::sys_install_crash_handlers", (const void*)w_sys_install_crash_handlers);
        csx_register_internal_call("Joy.Iocp::iocp_server_create", (const void*)w_iocp_server_create);
        csx_register_internal_call("Joy.Iocp::iocp_server_destroy", (const void*)w_iocp_server_destroy);
        csx_register_internal_call("Joy.Iocp::iocp_process_events", (const void*)w_iocp_process_events);
        csx_register_internal_call("Joy.Font::font_create", (const void*)w_font_create);
        csx_register_internal_call("Joy.Font::font_destroy", (const void*)w_font_destroy);
        csx_register_internal_call("Joy.Font::font_get_scale", (const void*)w_font_get_scale);
        csx_register_internal_call("Joy.Font::font_get_size", (const void*)w_font_get_size);
        csx_register_internal_call("Joy.Font::font_get_ascent", (const void*)w_font_get_ascent);
        csx_register_internal_call("Joy.R2d::r2d_create", (const void*)w_r2d_create);
        csx_register_internal_call("Joy.R2d::r2d_wrap", (const void*)w_r2d_wrap);
        csx_register_internal_call("Joy.R2d::r2d_destroy", (const void*)w_r2d_destroy);
        csx_register_internal_call("Joy.R2d::r2d_unwrap", (const void*)w_r2d_unwrap);
        csx_register_internal_call("Joy.R2d::r2d_begin", (const void*)w_r2d_begin);
        csx_register_internal_call("Joy.R2d::r2d_end", (const void*)w_r2d_end);
        csx_register_internal_call("Joy.R2d::r2d_set_logical_presentation", (const void*)w_r2d_set_logical_presentation);
        csx_register_internal_call("Joy.R2d::r2d_set_logical_presentation_mode", (const void*)w_r2d_set_logical_presentation_mode);
        csx_register_internal_call("Joy.R2d::r2d_set_vsync", (const void*)w_r2d_set_vsync);
        csx_register_internal_call("Joy.R2d::r2d_set_scale", (const void*)w_r2d_set_scale);
        csx_register_internal_call("Joy.R2d::r2d_set_colorf", (const void*)w_r2d_set_colorf);
        csx_register_internal_call("Joy.R2d::r2d_set_blend_mode", (const void*)w_r2d_set_blend_mode);
        csx_register_internal_call("Joy.R2d::r2d_draw_point", (const void*)w_r2d_draw_point);
        csx_register_internal_call("Joy.R2d::r2d_clear_clip", (const void*)w_r2d_clear_clip);
        csx_register_internal_call("Joy.R2d::r2d_pop_clip_rect", (const void*)w_r2d_pop_clip_rect);
        csx_register_internal_call("Joy.R2d::r2d_reset_clip_stack", (const void*)w_r2d_reset_clip_stack);
        csx_register_internal_call("Joy.R2d::r2d_point_in_clip", (const void*)w_r2d_point_in_clip);
        csx_register_internal_call("Joy.Shape::shape_draw_line", (const void*)w_shape_draw_line);
        csx_register_internal_call("Joy.Image::image_create", (const void*)w_image_create);
        csx_register_internal_call("Joy.Image::image_create_from_data", (const void*)w_image_create_from_data);
        csx_register_internal_call("Joy.Image::image_create_empty", (const void*)w_image_create_empty);
        csx_register_internal_call("Joy.Image::image_destroy", (const void*)w_image_destroy);
        csx_register_internal_call("Joy.Image::image_set_blend_mode", (const void*)w_image_set_blend_mode);
        csx_register_internal_call("Joy.Image::image_set_scale_mode", (const void*)w_image_set_scale_mode);
        csx_register_internal_call("Joy.Text::text_destroy", (const void*)w_text_destroy);
        csx_register_internal_call("Joy.Jtext::jtext_print", (const void*)w_jtext_print);
        csx_register_internal_call("Joy.R2d::r2d_draw_point_f", (const void*)w_r2d_draw_point_f);
        csx_register_internal_call("Joy.Shape::shape_draw_rectangle_f", (const void*)w_shape_draw_rectangle_f);
        csx_register_internal_call("Joy.Shape::shape_draw_line_f", (const void*)w_shape_draw_line_f);
        csx_register_internal_call("Joy.Text::text_get_width", (const void*)w_text_get_width);
        csx_register_internal_call("Joy.Text::text_get_height", (const void*)w_text_get_height);
        csx_register_internal_call("Joy.Jtext::jtext_cache_clear", (const void*)w_jtext_cache_clear);
        csx_register_internal_call("Joy.Jtext::jtext_cache_set_limit", (const void*)w_jtext_cache_set_limit);
        csx_register_internal_call("Joy.Jtext::jtext_cache_get_count", (const void*)w_jtext_cache_get_count);
        csx_register_internal_call("Joy.Jtext::jtext_cache_sweep", (const void*)w_jtext_cache_sweep);
        csx_register_internal_call("Joy.Animation::animation_create", (const void*)w_animation_create);
        csx_register_internal_call("Joy.Animation::animation_destroy", (const void*)w_animation_destroy);
        csx_register_internal_call("Joy.Animation::animation_reset", (const void*)w_animation_reset);
        csx_register_internal_call("Joy.Animation::animation_is_finished", (const void*)w_animation_is_finished);
        csx_register_internal_call("Joy.Animation::animation_set_position", (const void*)w_animation_set_position);
        csx_register_internal_call("Joy.Animation::animation_set_scale", (const void*)w_animation_set_scale);
        csx_register_internal_call("Joy.Animation::animation_set_rotation", (const void*)w_animation_set_rotation);
        csx_register_internal_call("Joy.Animation::animation_update", (const void*)w_animation_update);
        csx_register_internal_call("Joy.R3d::r3d_load_shader", (const void*)w_r3d_load_shader);
        csx_register_internal_call("Joy.R3d::r3d_create_pipeline", (const void*)w_r3d_create_pipeline);
        csx_register_internal_call("Joy.R3d::r3d_upload_buffer", (const void*)w_r3d_upload_buffer);
        csx_register_internal_call("Joy.R3d::r3d_create_depth_texture", (const void*)w_r3d_create_depth_texture);
        csx_register_internal_call("Joy.R3d::r3d_create_sampler", (const void*)w_r3d_create_sampler);
        csx_register_internal_call("Joy.R3d::r3d_create", (const void*)w_r3d_create);
        csx_register_internal_call("Joy.R3d::r3d_destroy", (const void*)w_r3d_destroy);
        csx_register_internal_call("Joy.R3d::r3d_get_device", (const void*)w_r3d_get_device);
        csx_register_internal_call("Joy.R3d::r3d_begin", (const void*)w_r3d_begin);
        csx_register_internal_call("Joy.R3d::r3d_end", (const void*)w_r3d_end);
        csx_register_internal_call("Joy.R3d::r3d_get_draw_calls", (const void*)w_r3d_get_draw_calls);
        csx_register_internal_call("Joy.R3d::r3d_mesh_cube", (const void*)w_r3d_mesh_cube);
        csx_register_internal_call("Joy.R3d::r3d_mesh_sphere", (const void*)w_r3d_mesh_sphere);
        csx_register_internal_call("Joy.R3d::r3d_mesh_plane", (const void*)w_r3d_mesh_plane);
        csx_register_internal_call("Joy.R3d::r3d_mesh_ramp", (const void*)w_r3d_mesh_ramp);
        csx_register_internal_call("Joy.R3d::r3d_mesh_custom", (const void*)w_r3d_mesh_custom);
        csx_register_internal_call("Joy.R3d::r3d_mesh_quad", (const void*)w_r3d_mesh_quad);
        csx_register_internal_call("Joy.R3d::r3d_mesh_cube_wire", (const void*)w_r3d_mesh_cube_wire);
        csx_register_internal_call("Joy.R3d::r3d_mesh_sphere_wire", (const void*)w_r3d_mesh_sphere_wire);
        csx_register_internal_call("Joy.R3d::r3d_mesh_plane_wire", (const void*)w_r3d_mesh_plane_wire);
        csx_register_internal_call("Joy.R3d::r3d_mesh_ramp_wire", (const void*)w_r3d_mesh_ramp_wire);
        csx_register_internal_call("Joy.R3d::r3d_mesh_destroy", (const void*)w_r3d_mesh_destroy);
        csx_register_internal_call("Joy.R3d::r3d_create_texture", (const void*)w_r3d_create_texture);
        csx_register_internal_call("Joy.R3d::r3d_gen_checkerboard", (const void*)w_r3d_gen_checkerboard);
        csx_register_internal_call("Joy.R3d::r3d_font_init", (const void*)w_r3d_font_init);
        csx_register_internal_call("Joy.R3d::r3d_font_draw_2d", (const void*)w_r3d_font_draw_2d);
        csx_register_internal_call("Joy.R3d::r3d_font_cache_set_limit", (const void*)w_r3d_font_cache_set_limit);
        csx_register_internal_call("Joy.R3d::r3d_font_cache_get_count", (const void*)w_r3d_font_cache_get_count);
        csx_register_internal_call("Joy.R3d::r3d_font_cache_clear", (const void*)w_r3d_font_cache_clear);
        csx_register_internal_call("Joy.R3d::r3d_font_cache_sweep", (const void*)w_r3d_font_cache_sweep);
        csx_register_internal_call("Joy.R3d::r3d_set_logical_presentation", (const void*)w_r3d_set_logical_presentation);
        csx_register_internal_call("Joy.R3d::r3d_set_logical_presentation_mode", (const void*)w_r3d_set_logical_presentation_mode);
        csx_register_internal_call("Joy.R3d::r3d_button_create", (const void*)w_r3d_button_create);
        csx_register_internal_call("Joy.R3d::r3d_button_draw", (const void*)w_r3d_button_draw);
        csx_register_internal_call("Joy.R3d::r3d_button_draw_circle", (const void*)w_r3d_button_draw_circle);
        csx_register_internal_call("Joy.R3d::r3d_button_is_hovered", (const void*)w_r3d_button_is_hovered);
        csx_register_internal_call("Joy.R3d::r3d_button_is_pressed", (const void*)w_r3d_button_is_pressed);
        csx_register_internal_call("Joy.R3d::r3d_button_release", (const void*)w_r3d_button_release);
        csx_register_internal_call("Joy.R3d::r3d_button_destroy", (const void*)w_r3d_button_destroy);
        csx_register_internal_call("Joy.R3d::r3d_draw_tex_2d", (const void*)w_r3d_draw_tex_2d);
        csx_register_internal_call("Joy.R3d::r3d_label_set_text", (const void*)w_r3d_label_set_text);
        csx_register_internal_call("Joy.R3d::r3d_label_draw", (const void*)w_r3d_label_draw);
        csx_register_internal_call("Joy.R3d::r3d_label_destroy", (const void*)w_r3d_label_destroy);
        csx_register_internal_call("Joy.R3d::r3d_input_set_text", (const void*)w_r3d_input_set_text);
        csx_register_internal_call("Joy.R3d::r3d_input_is_hovered", (const void*)w_r3d_input_is_hovered);
        csx_register_internal_call("Joy.R3d::r3d_input_focus", (const void*)w_r3d_input_focus);
        csx_register_internal_call("Joy.R3d::r3d_input_defocus", (const void*)w_r3d_input_defocus);
        csx_register_internal_call("Joy.R3d::r3d_input_is_focused", (const void*)w_r3d_input_is_focused);
        csx_register_internal_call("Joy.R3d::r3d_input_start_text_input", (const void*)w_r3d_input_start_text_input);
        csx_register_internal_call("Joy.R3d::r3d_input_stop_text_input", (const void*)w_r3d_input_stop_text_input);
        csx_register_internal_call("Joy.R3d::r3d_input_insert", (const void*)w_r3d_input_insert);
        csx_register_internal_call("Joy.R3d::r3d_input_backspace", (const void*)w_r3d_input_backspace);
        csx_register_internal_call("Joy.R3d::r3d_input_delete", (const void*)w_r3d_input_delete);
        csx_register_internal_call("Joy.R3d::r3d_input_cursor_left", (const void*)w_r3d_input_cursor_left);
        csx_register_internal_call("Joy.R3d::r3d_input_cursor_right", (const void*)w_r3d_input_cursor_right);
        csx_register_internal_call("Joy.R3d::r3d_input_cursor_home", (const void*)w_r3d_input_cursor_home);
        csx_register_internal_call("Joy.R3d::r3d_input_cursor_end", (const void*)w_r3d_input_cursor_end);
        csx_register_internal_call("Joy.R3d::r3d_input_click", (const void*)w_r3d_input_click);
        csx_register_internal_call("Joy.R3d::r3d_input_submit", (const void*)w_r3d_input_submit);
        csx_register_internal_call("Joy.R3d::r3d_input_draw", (const void*)w_r3d_input_draw);
        csx_register_internal_call("Joy.R3d::r3d_input_destroy", (const void*)w_r3d_input_destroy);
        csx_register_internal_call("Joy.R3d::r3d_combobox_input_destroy", (const void*)w_r3d_combobox_input_destroy);
        csx_register_internal_call("Joy.R3d::r3d_combobox_input_add_item", (const void*)w_r3d_combobox_input_add_item);
        csx_register_internal_call("Joy.R3d::r3d_combobox_input_clear_items", (const void*)w_r3d_combobox_input_clear_items);
        csx_register_internal_call("Joy.R3d::r3d_combobox_input_set_text", (const void*)w_r3d_combobox_input_set_text);
        csx_register_internal_call("Joy.R3d::r3d_combobox_input_hit_item", (const void*)w_r3d_combobox_input_hit_item);
        csx_register_internal_call("Joy.R3d::r3d_combobox_input_draw", (const void*)w_r3d_combobox_input_draw);
        csx_register_internal_call("Joy.R3d::r3d_combobox_input_draw_dropdown", (const void*)w_r3d_combobox_input_draw_dropdown);
        csx_register_internal_call("Joy.R3d::r3d_slider_create", (const void*)w_r3d_slider_create);
        csx_register_internal_call("Joy.R3d::r3d_slider_destroy", (const void*)w_r3d_slider_destroy);
        csx_register_internal_call("Joy.R3d::r3d_slider_set_value", (const void*)w_r3d_slider_set_value);
        csx_register_internal_call("Joy.R3d::r3d_slider_get_value", (const void*)w_r3d_slider_get_value);
        csx_register_internal_call("Joy.R3d::r3d_slider_draw", (const void*)w_r3d_slider_draw);
        csx_register_internal_call("Joy.R3d::r3d_slider_is_pressed", (const void*)w_r3d_slider_is_pressed);
        csx_register_internal_call("Joy.R3d::r3d_slider_set_pressed", (const void*)w_r3d_slider_set_pressed);
        csx_register_internal_call("Joy.R3d::r3d_slider_drag_move", (const void*)w_r3d_slider_drag_move);
        csx_register_internal_call("Joy.R3d::r3d_slider_is_hovered", (const void*)w_r3d_slider_is_hovered);
        csx_register_internal_call("Joy.R3d::r3d_slider_set_hovered", (const void*)w_r3d_slider_set_hovered);
        csx_register_internal_call("Joy.R3d::r3d_checkbox_create", (const void*)w_r3d_checkbox_create);
        csx_register_internal_call("Joy.R3d::r3d_checkbox_destroy", (const void*)w_r3d_checkbox_destroy);
        csx_register_internal_call("Joy.R3d::r3d_checkbox_toggle", (const void*)w_r3d_checkbox_toggle);
        csx_register_internal_call("Joy.R3d::r3d_checkbox_is_pressed", (const void*)w_r3d_checkbox_is_pressed);
        csx_register_internal_call("Joy.R3d::r3d_checkbox_set_hovered", (const void*)w_r3d_checkbox_set_hovered);
        csx_register_internal_call("Joy.R3d::r3d_checkbox_is_hovered", (const void*)w_r3d_checkbox_is_hovered);
        csx_register_internal_call("Joy.R3d::r3d_checkbox_draw", (const void*)w_r3d_checkbox_draw);
        csx_register_internal_call("Joy.R3d::r3d_draw_grid", (const void*)w_r3d_draw_grid);
        csx_register_internal_call("Joy.R3d::r3d_create_line_pipeline", (const void*)w_r3d_create_line_pipeline);
        csx_register_internal_call("Joy.R3d::r3d_create_lighting_pipeline", (const void*)w_r3d_create_lighting_pipeline);
        csx_register_internal_call("Joy.R3d::r3d_mesh_cube_lit", (const void*)w_r3d_mesh_cube_lit);
        csx_register_internal_call("Joy.R3d::r3d_mesh_sphere_lit", (const void*)w_r3d_mesh_sphere_lit);
        csx_register_internal_call("Joy.R3d::r3d_mesh_plane_lit", (const void*)w_r3d_mesh_plane_lit);
        csx_register_internal_call("Joy.R3d::r3d_mesh_ramp_lit", (const void*)w_r3d_mesh_ramp_lit);
        csx_register_internal_call("Joy.R3d::r3d_mesh_custom_lit", (const void*)w_r3d_mesh_custom_lit);
        csx_register_internal_call("Joy.Janimator::janimator_create", (const void*)w_janimator_create);
        csx_register_internal_call("Joy.Janimator::janimator_destroy", (const void*)w_janimator_destroy);
        csx_register_internal_call("Joy.Janimator::janimator_set_float", (const void*)w_janimator_set_float);
        csx_register_internal_call("Joy.Janimator::janimator_set_int", (const void*)w_janimator_set_int);
        csx_register_internal_call("Joy.Janimator::janimator_set_bool", (const void*)w_janimator_set_bool);
        csx_register_internal_call("Joy.Janimator::janimator_set_trigger", (const void*)w_janimator_set_trigger);
        csx_register_internal_call("Joy.Janimator::janimator_get_float", (const void*)w_janimator_get_float);
        csx_register_internal_call("Joy.Janimator::janimator_get_int", (const void*)w_janimator_get_int);
        csx_register_internal_call("Joy.Janimator::janimator_get_bool", (const void*)w_janimator_get_bool);
        csx_register_internal_call("Joy.Janimator::janimator_add_state", (const void*)w_janimator_add_state);
        csx_register_internal_call("Joy.Janimator::janimator_set_default_state", (const void*)w_janimator_set_default_state);
        csx_register_internal_call("Joy.Janimator::janimator_state_set_loop", (const void*)w_janimator_state_set_loop);
        csx_register_internal_call("Joy.Janimator::janimator_state_set_speed", (const void*)w_janimator_state_set_speed);
        csx_register_internal_call("Joy.Janimator::janimator_state_set_blend", (const void*)w_janimator_state_set_blend);
        csx_register_internal_call("Joy.Janimator::janimator_add_transition", (const void*)w_janimator_add_transition);
        csx_register_internal_call("Joy.Janimator::janimator_add_any_transition", (const void*)w_janimator_add_any_transition);
        csx_register_internal_call("Joy.Janimator::janimator_transition_add_cond", (const void*)w_janimator_transition_add_cond);
        csx_register_internal_call("Joy.Janimator::janimator_transition_set_exit_time", (const void*)w_janimator_transition_set_exit_time);
        csx_register_internal_call("Joy.Janimator::janimator_update", (const void*)w_janimator_update);
        csx_register_internal_call("Joy.Janimator::janimator_draw", (const void*)w_janimator_draw);
        csx_register_internal_call("Joy.Janimator::janimator_set_flip_h", (const void*)w_janimator_set_flip_h);
        csx_register_internal_call("Joy.Label::label_destroy", (const void*)w_label_destroy);
        csx_register_internal_call("Joy.Label::label_draw", (const void*)w_label_draw);
        csx_register_internal_call("Joy.Label::label_process_event", (const void*)w_label_process_event);
        csx_register_internal_call("Joy.Button::button_create", (const void*)w_button_create);
        csx_register_internal_call("Joy.Button::button_destroy", (const void*)w_button_destroy);
        csx_register_internal_call("Joy.Button::button_set_position", (const void*)w_button_set_position);
        csx_register_internal_call("Joy.Button::button_set_size", (const void*)w_button_set_size);
        csx_register_internal_call("Joy.Button::button_set_image", (const void*)w_button_set_image);
        csx_register_internal_call("Joy.Button::button_set_pressed_image", (const void*)w_button_set_pressed_image);
        csx_register_internal_call("Joy.Button::button_is_hovered", (const void*)w_button_is_hovered);
        csx_register_internal_call("Joy.Button::button_is_pressed", (const void*)w_button_is_pressed);
        csx_register_internal_call("Joy.Button::button_set_hovered", (const void*)w_button_set_hovered);
        csx_register_internal_call("Joy.Button::button_set_pressed", (const void*)w_button_set_pressed);
        csx_register_internal_call("Joy.Button::button_get_pressed", (const void*)w_button_get_pressed);
        csx_register_internal_call("Joy.Button::button_set_text_offset", (const void*)w_button_set_text_offset);
        csx_register_internal_call("Joy.Button::button_draw", (const void*)w_button_draw);
        csx_register_internal_call("Joy.Button::button_process_event", (const void*)w_button_process_event);
        csx_register_internal_call("Joy.Scrollview::scrollview_create", (const void*)w_scrollview_create);
        csx_register_internal_call("Joy.Scrollview::scrollview_destroy", (const void*)w_scrollview_destroy);
        csx_register_internal_call("Joy.Scrollview::scrollview_set_view_px", (const void*)w_scrollview_set_view_px);
        csx_register_internal_call("Joy.Scrollview::scrollview_set_content", (const void*)w_scrollview_set_content);
        csx_register_internal_call("Joy.Scrollview::scrollview_set_offset", (const void*)w_scrollview_set_offset);
        csx_register_internal_call("Joy.Scrollview::scrollview_clamp", (const void*)w_scrollview_clamp);
        csx_register_internal_call("Joy.Scrollview::scrollview_get_offset_x", (const void*)w_scrollview_get_offset_x);
        csx_register_internal_call("Joy.Scrollview::scrollview_get_offset_y", (const void*)w_scrollview_get_offset_y);
        csx_register_internal_call("Joy.Scrollview::scrollview_set_show_bar", (const void*)w_scrollview_set_show_bar);
        csx_register_internal_call("Joy.Scrollview::scrollview_dragging", (const void*)w_scrollview_dragging);
        csx_register_internal_call("Joy.Scrollview::scrollview_hit", (const void*)w_scrollview_hit);
        csx_register_internal_call("Joy.Scrollview::scrollview_begin", (const void*)w_scrollview_begin);
        csx_register_internal_call("Joy.Scrollview::scrollview_end", (const void*)w_scrollview_end);
        csx_register_internal_call("Joy.Scrollview::scrollview_process_event", (const void*)w_scrollview_process_event);
        csx_register_internal_call("Joy.Combobox::combobox_create", (const void*)w_combobox_create);
        csx_register_internal_call("Joy.Combobox::combobox_destroy", (const void*)w_combobox_destroy);
        csx_register_internal_call("Joy.Combobox::combobox_is_pressed", (const void*)w_combobox_is_pressed);
        csx_register_internal_call("Joy.Combobox::combobox_is_open", (const void*)w_combobox_is_open);
        csx_register_internal_call("Joy.Combobox::combobox_set_open", (const void*)w_combobox_set_open);
        csx_register_internal_call("Joy.Combobox::combobox_hit_item", (const void*)w_combobox_hit_item);
        csx_register_internal_call("Joy.Combobox::combobox_set_selected", (const void*)w_combobox_set_selected);
        csx_register_internal_call("Joy.Combobox::combobox_get_selected", (const void*)w_combobox_get_selected);
        csx_register_internal_call("Joy.Combobox::combobox_draw", (const void*)w_combobox_draw);
        csx_register_internal_call("Joy.Combobox::combobox_process_event", (const void*)w_combobox_process_event);
        csx_register_internal_call("Joy.Combobox::combobox_input_create", (const void*)w_combobox_input_create);
        csx_register_internal_call("Joy.Combobox::combobox_input_destroy", (const void*)w_combobox_input_destroy);
        csx_register_internal_call("Joy.Combobox::combobox_input_add_item", (const void*)w_combobox_input_add_item);
        csx_register_internal_call("Joy.Combobox::combobox_input_clear_items", (const void*)w_combobox_input_clear_items);
        csx_register_internal_call("Joy.Combobox::combobox_input_set_text", (const void*)w_combobox_input_set_text);
        csx_register_internal_call("Joy.Combobox::combobox_input_draw", (const void*)w_combobox_input_draw);
        csx_register_internal_call("Joy.Combobox::combobox_input_draw_dropdown", (const void*)w_combobox_input_draw_dropdown);
        csx_register_internal_call("Joy.Combobox::combobox_input_is_open", (const void*)w_combobox_input_is_open);
        csx_register_internal_call("Joy.Combobox::combobox_input_set_popup_node", (const void*)w_combobox_input_set_popup_node);
        csx_register_internal_call("Joy.Combobox::combobox_input_process_event", (const void*)w_combobox_input_process_event);
        csx_register_internal_call("Joy.Combobox::combobox_input_hit_item", (const void*)w_combobox_input_hit_item);
        csx_register_internal_call("Joy.Combobox::combobox_input_set_open", (const void*)w_combobox_input_set_open);
        csx_register_internal_call("Joy.Datagrid::datagrid_create", (const void*)w_datagrid_create);
        csx_register_internal_call("Joy.Datagrid::datagrid_setheaders", (const void*)w_datagrid_setheaders);
        csx_register_internal_call("Joy.Datagrid::datagrid_setheader", (const void*)w_datagrid_setheader);
        csx_register_internal_call("Joy.Datagrid::datagrid_setcell", (const void*)w_datagrid_setcell);
        csx_register_internal_call("Joy.Datagrid::datagrid_destroy", (const void*)w_datagrid_destroy);
        csx_register_internal_call("Joy.Datagrid::datagrid_draw", (const void*)w_datagrid_draw);
        csx_register_internal_call("Joy.Datagrid::datagrid_hit_row", (const void*)w_datagrid_hit_row);
        csx_register_internal_call("Joy.Datagrid::datagrid_scroll", (const void*)w_datagrid_scroll);
        csx_register_internal_call("Joy.Datagrid::datagrid_set_selected_row", (const void*)w_datagrid_set_selected_row);
        csx_register_internal_call("Joy.Datagrid::datagrid_process_event", (const void*)w_datagrid_process_event);
        csx_register_internal_call("Joy.Radio::radio_create", (const void*)w_radio_create);
        csx_register_internal_call("Joy.Radio::radio_destroy", (const void*)w_radio_destroy);
        csx_register_internal_call("Joy.Radio::radio_is_pressed", (const void*)w_radio_is_pressed);
        csx_register_internal_call("Joy.Radio::radio_set_hovered", (const void*)w_radio_set_hovered);
        csx_register_internal_call("Joy.Radio::radio_process_event", (const void*)w_radio_process_event);
        csx_register_internal_call("Joy.Checkbox::checkbox_create", (const void*)w_checkbox_create);
        csx_register_internal_call("Joy.Checkbox::checkbox_destroy", (const void*)w_checkbox_destroy);
        csx_register_internal_call("Joy.Checkbox::checkbox_set_r2d", (const void*)w_checkbox_set_r2d);
        csx_register_internal_call("Joy.Checkbox::checkbox_set_position", (const void*)w_checkbox_set_position);
        csx_register_internal_call("Joy.Checkbox::checkbox_toggle", (const void*)w_checkbox_toggle);
        csx_register_internal_call("Joy.Checkbox::checkbox_is_pressed", (const void*)w_checkbox_is_pressed);
        csx_register_internal_call("Joy.Checkbox::checkbox_set_hovered", (const void*)w_checkbox_set_hovered);
        csx_register_internal_call("Joy.Checkbox::checkbox_draw", (const void*)w_checkbox_draw);
        csx_register_internal_call("Joy.Checkbox::checkbox_process_event", (const void*)w_checkbox_process_event);
        csx_register_internal_call("Joy.Joystick::joystick_create", (const void*)w_joystick_create);
        csx_register_internal_call("Joy.Joystick::joystick_destroy", (const void*)w_joystick_destroy);
        csx_register_internal_call("Joy.Joystick::joystick_set_textures", (const void*)w_joystick_set_textures);
        csx_register_internal_call("Joy.Joystick::joystick_set_vector", (const void*)w_joystick_set_vector);
        csx_register_internal_call("Joy.Joystick::joystick_draw", (const void*)w_joystick_draw);
        csx_register_internal_call("Joy.Joystick::joystick_reset", (const void*)w_joystick_reset);
        csx_register_internal_call("Joy.Joystick::joystick_set_position", (const void*)w_joystick_set_position);
        csx_register_internal_call("Joy.Joystick::joystick_set_radius", (const void*)w_joystick_set_radius);
        csx_register_internal_call("Joy.Joystick::joystick_is_dragging", (const void*)w_joystick_is_dragging);
        csx_register_internal_call("Joy.Joystick::joystick_touch_down", (const void*)w_joystick_touch_down);
        csx_register_internal_call("Joy.Joystick::joystick_touch_move", (const void*)w_joystick_touch_move);
        csx_register_internal_call("Joy.Joystick::joystick_touch_up", (const void*)w_joystick_touch_up);
        csx_register_internal_call("Joy.Joystick::joystick_get_magnitude", (const void*)w_joystick_get_magnitude);
        csx_register_internal_call("Joy.Joystick::joystick_process_event", (const void*)w_joystick_process_event);
        csx_register_internal_call("Joy.Inputbox::inputbox_create", (const void*)w_inputbox_create);
        csx_register_internal_call("Joy.Inputbox::inputbox_destroy", (const void*)w_inputbox_destroy);
        csx_register_internal_call("Joy.Inputbox::inputbox_set_text", (const void*)w_inputbox_set_text);
        csx_register_internal_call("Joy.Inputbox::inputbox_draw", (const void*)w_inputbox_draw);
        csx_register_internal_call("Joy.Inputbox::inputbox_is_pressed", (const void*)w_inputbox_is_pressed);
        csx_register_internal_call("Joy.Inputbox::inputbox_is_hovered", (const void*)w_inputbox_is_hovered);
        csx_register_internal_call("Joy.Inputbox::inputbox_focus", (const void*)w_inputbox_focus);
        csx_register_internal_call("Joy.Inputbox::inputbox_defocus", (const void*)w_inputbox_defocus);
        csx_register_internal_call("Joy.Inputbox::inputbox_blur", (const void*)w_inputbox_blur);
        csx_register_internal_call("Joy.Inputbox::inputbox_insert", (const void*)w_inputbox_insert);
        csx_register_internal_call("Joy.Inputbox::inputbox_backspace", (const void*)w_inputbox_backspace);
        csx_register_internal_call("Joy.Inputbox::inputbox_delete", (const void*)w_inputbox_delete);
        csx_register_internal_call("Joy.Inputbox::inputbox_cursor_left", (const void*)w_inputbox_cursor_left);
        csx_register_internal_call("Joy.Inputbox::inputbox_cursor_right", (const void*)w_inputbox_cursor_right);
        csx_register_internal_call("Joy.Inputbox::inputbox_cursor_home", (const void*)w_inputbox_cursor_home);
        csx_register_internal_call("Joy.Inputbox::inputbox_cursor_end", (const void*)w_inputbox_cursor_end);
        csx_register_internal_call("Joy.Inputbox::inputbox_select_left", (const void*)w_inputbox_select_left);
        csx_register_internal_call("Joy.Inputbox::inputbox_select_right", (const void*)w_inputbox_select_right);
        csx_register_internal_call("Joy.Inputbox::inputbox_select_home", (const void*)w_inputbox_select_home);
        csx_register_internal_call("Joy.Inputbox::inputbox_select_end", (const void*)w_inputbox_select_end);
        csx_register_internal_call("Joy.Inputbox::inputbox_select_all", (const void*)w_inputbox_select_all);
        csx_register_internal_call("Joy.Inputbox::inputbox_paste", (const void*)w_inputbox_paste);
        csx_register_internal_call("Joy.Inputbox::inputbox_copy", (const void*)w_inputbox_copy);
        csx_register_internal_call("Joy.Inputbox::inputbox_cut", (const void*)w_inputbox_cut);
        csx_register_internal_call("Joy.Inputbox::inputbox_is_focused", (const void*)w_inputbox_is_focused);
        csx_register_internal_call("Joy.Inputbox::inputbox_process_event", (const void*)w_inputbox_process_event);
        csx_register_internal_call("Joy.Slider::slider_create", (const void*)w_slider_create);
        csx_register_internal_call("Joy.Slider::slider_destroy", (const void*)w_slider_destroy);
        csx_register_internal_call("Joy.Slider::slider_set_value", (const void*)w_slider_set_value);
        csx_register_internal_call("Joy.Slider::slider_get_value", (const void*)w_slider_get_value);
        csx_register_internal_call("Joy.Slider::slider_set_rect", (const void*)w_slider_set_rect);
        csx_register_internal_call("Joy.Slider::slider_set_range", (const void*)w_slider_set_range);
        csx_register_internal_call("Joy.Slider::slider_draw", (const void*)w_slider_draw);
        csx_register_internal_call("Joy.Slider::slider_is_pressed", (const void*)w_slider_is_pressed);
        csx_register_internal_call("Joy.Slider::slider_set_pressed", (const void*)w_slider_set_pressed);
        csx_register_internal_call("Joy.Slider::slider_drag_move", (const void*)w_slider_drag_move);
        csx_register_internal_call("Joy.Slider::slider_is_hovered", (const void*)w_slider_is_hovered);
        csx_register_internal_call("Joy.Slider::slider_set_hovered", (const void*)w_slider_set_hovered);
        csx_register_internal_call("Joy.Slider::slider_process_event", (const void*)w_slider_process_event);
        csx_register_internal_call("Joy.Popup::popup_create", (const void*)w_popup_create);
        csx_register_internal_call("Joy.Popup::popup_destroy", (const void*)w_popup_destroy);
        csx_register_internal_call("Joy.Popup::popup_set_title", (const void*)w_popup_set_title);
        csx_register_internal_call("Joy.Popup::popup_set_content", (const void*)w_popup_set_content);
        csx_register_internal_call("Joy.Popup::popup_set_position", (const void*)w_popup_set_position);
        csx_register_internal_call("Joy.Popup::popup_set_visible", (const void*)w_popup_set_visible);
        csx_register_internal_call("Joy.Popup::popup_set_closeable", (const void*)w_popup_set_closeable);
        csx_register_internal_call("Joy.Popup::popup_draw", (const void*)w_popup_draw);
        csx_register_internal_call("Joy.Popup::popup_is_close_clicked", (const void*)w_popup_is_close_clicked);
        csx_register_internal_call("Joy.Popup::popup_is_title_clicked", (const void*)w_popup_is_title_clicked);
        csx_register_internal_call("Joy.Popup::popup_drag_move", (const void*)w_popup_drag_move);
        csx_register_internal_call("Joy.Popup::popup_is_inside", (const void*)w_popup_is_inside);
        csx_register_internal_call("Joy.Popup::popup_process_event", (const void*)w_popup_process_event);
        csx_register_internal_call("Joy.Tooltip::tooltip_create", (const void*)w_tooltip_create);
        csx_register_internal_call("Joy.Tooltip::tooltip_destroy", (const void*)w_tooltip_destroy);
        csx_register_internal_call("Joy.Tooltip::tooltip_set_text", (const void*)w_tooltip_set_text);
        csx_register_internal_call("Joy.Tooltip::tooltip_set_position", (const void*)w_tooltip_set_position);
        csx_register_internal_call("Joy.Tooltip::tooltip_set_visible", (const void*)w_tooltip_set_visible);
        csx_register_internal_call("Joy.Tooltip::tooltip_draw", (const void*)w_tooltip_draw);
        csx_register_internal_call("Joy.Tooltip::tooltip_process_event", (const void*)w_tooltip_process_event);
        csx_register_internal_call("Joy.Jui::jui_ctx_create", (const void*)w_jui_ctx_create);
        csx_register_internal_call("Joy.Jui::jui_ctx_destroy", (const void*)w_jui_ctx_destroy);
        csx_register_internal_call("Joy.Jui::jui_begin", (const void*)w_jui_begin);
        csx_register_internal_call("Joy.Jui::jui_end", (const void*)w_jui_end);
        csx_register_internal_call("Joy.Jui::jui_input_motion", (const void*)w_jui_input_motion);
        csx_register_internal_call("Joy.Jui::jui_input_down", (const void*)w_jui_input_down);
        csx_register_internal_call("Joy.Jui::jui_input_up", (const void*)w_jui_input_up);
        csx_register_internal_call("Joy.Jui::jui_input_wheel", (const void*)w_jui_input_wheel);
        csx_register_internal_call("Joy.Jui::jui_input_key", (const void*)w_jui_input_key);
        csx_register_internal_call("Joy.Jui::jui_is_down", (const void*)w_jui_is_down);
        csx_register_internal_call("Joy.Jui::jui_is_pressed", (const void*)w_jui_is_pressed);
        csx_register_internal_call("Joy.Jui::jui_is_released", (const void*)w_jui_is_released);
        csx_register_internal_call("Joy.Jui::jui_take_wheel", (const void*)w_jui_take_wheel);
        csx_register_internal_call("Joy.Jui::jui_is_shift", (const void*)w_jui_is_shift);
        csx_register_internal_call("Joy.Jui::jui_is_ctrl", (const void*)w_jui_is_ctrl);
        csx_register_internal_call("Joy.Jui::jui_pop_clip", (const void*)w_jui_pop_clip);
        csx_register_internal_call("Joy.Jui::jui_reset_clip", (const void*)w_jui_reset_clip);
        csx_register_internal_call("Joy.Jui::jui_panel_end", (const void*)w_jui_panel_end);
        csx_register_internal_call("Joy.Jui::jui_scroll_end", (const void*)w_jui_scroll_end);
        csx_register_internal_call("Joy.Jui::jui_scroll_set_offset", (const void*)w_jui_scroll_set_offset);
        csx_register_internal_call("Joy.Jtilemap::jtilemap_load_file_json", (const void*)w_jtilemap_load_file_json);
        csx_register_internal_call("Joy.Jtilemap::jtilemap_destroy", (const void*)w_jtilemap_destroy);
        csx_register_internal_call("Joy.Jtilemap::jtilemap_get_width", (const void*)w_jtilemap_get_width);
        csx_register_internal_call("Joy.Jtilemap::jtilemap_get_height", (const void*)w_jtilemap_get_height);
        csx_register_internal_call("Joy.Jtilemap::jtilemap_get_tilewidth", (const void*)w_jtilemap_get_tilewidth);
        csx_register_internal_call("Joy.Jtilemap::jtilemap_get_tileheight", (const void*)w_jtilemap_get_tileheight);
        csx_register_internal_call("Joy.Jtilemap::jtilemap_get_anim_tileid", (const void*)w_jtilemap_get_anim_tileid);
        csx_register_internal_call("Joy.Jtilemap::jtilemap_find_tile_layer", (const void*)w_jtilemap_find_tile_layer);
        csx_register_internal_call("Joy.Jtilemap::jtilemap_find_object_layer", (const void*)w_jtilemap_find_object_layer);
        csx_register_internal_call("Joy.Jtilemap::jtilemap_get_tile", (const void*)w_jtilemap_get_tile);
        csx_register_internal_call("Joy.Jtilemap::jtilemap_render_all", (const void*)w_jtilemap_render_all);
        csx_register_internal_call("Joy.Jtilemap::jtilemap_render_tiles", (const void*)w_jtilemap_render_tiles);
        csx_register_internal_call("Joy.Jtilemap::jtilemap_render_set_tile_px", (const void*)w_jtilemap_render_set_tile_px);
        csx_register_internal_call("Joy.Jtilemap::jtilemap_render_layer", (const void*)w_jtilemap_render_layer);
        csx_register_internal_call("Joy.Jtilemap::jtilemap_render_destroy", (const void*)w_jtilemap_render_destroy);
        csx_register_internal_call("Joy.Kcpserver::kcpserver_create", (const void*)w_kcpserver_create);
        csx_register_internal_call("Joy.Kcpserver::kcpserver_destroy", (const void*)w_kcpserver_destroy);
        csx_register_internal_call("Joy.Kcpserver::kcpserver_send", (const void*)w_kcpserver_send);
        csx_register_internal_call("Joy.Kcpserver::kcpserver_broadcast", (const void*)w_kcpserver_broadcast);
        csx_register_internal_call("Joy.Kcpserver::kcpserver_offline", (const void*)w_kcpserver_offline);
        csx_register_internal_call("Joy.Kcpserver::kcpserver_update", (const void*)w_kcpserver_update);
        csx_register_internal_call("Joy.Kcpserver::kcpserver_connection_count", (const void*)w_kcpserver_connection_count);
        csx_register_internal_call("Joy.Kcpserver::kcpserver_poll_message", (const void*)w_kcpserver_poll_message);
        csx_register_internal_call("Joy.Kcpclient::kcpclient_create", (const void*)w_kcpclient_create);
        csx_register_internal_call("Joy.Kcpclient::kcpclient_destroy", (const void*)w_kcpclient_destroy);
        csx_register_internal_call("Joy.Kcpclient::kcpclient_send", (const void*)w_kcpclient_send);
        csx_register_internal_call("Joy.Kcpclient::kcpclient_update", (const void*)w_kcpclient_update);
        csx_register_internal_call("Joy.Kcpclient::kcpclient_poll_message", (const void*)w_kcpclient_poll_message);
        csx_register_internal_call("Joy.Tcpserver::tcpserver_create", (const void*)w_tcpserver_create);
        csx_register_internal_call("Joy.Tcpserver::tcpserver_destroy", (const void*)w_tcpserver_destroy);
        csx_register_internal_call("Joy.Tcpserver::tcpserver_send", (const void*)w_tcpserver_send);
        csx_register_internal_call("Joy.Tcpserver::tcpserver_broadcast", (const void*)w_tcpserver_broadcast);
        csx_register_internal_call("Joy.Tcpserver::tcpserver_offline", (const void*)w_tcpserver_offline);
        csx_register_internal_call("Joy.Tcpserver::tcpserver_update", (const void*)w_tcpserver_update);
        csx_register_internal_call("Joy.Tcpserver::tcpserver_connection_count", (const void*)w_tcpserver_connection_count);
        csx_register_internal_call("Joy.Tcpserver::tcpserver_poll_message", (const void*)w_tcpserver_poll_message);
        csx_register_internal_call("Joy.Tcpclient::tcpclient_create", (const void*)w_tcpclient_create);
        csx_register_internal_call("Joy.Tcpclient::tcpclient_destroy", (const void*)w_tcpclient_destroy);
        csx_register_internal_call("Joy.Tcpclient::tcpclient_send", (const void*)w_tcpclient_send);
        csx_register_internal_call("Joy.Tcpclient::tcpclient_update", (const void*)w_tcpclient_update);
        csx_register_internal_call("Joy.Tcpclient::tcpclient_poll_message", (const void*)w_tcpclient_poll_message);
        csx_register_internal_call("Joy.Wsnetserver::wsnetserver_create", (const void*)w_wsnetserver_create);
        csx_register_internal_call("Joy.Wsnetserver::wsnetserver_destroy", (const void*)w_wsnetserver_destroy);
        csx_register_internal_call("Joy.Wsnetserver::wsnetserver_send", (const void*)w_wsnetserver_send);
        csx_register_internal_call("Joy.Wsnetserver::wsnetserver_broadcast", (const void*)w_wsnetserver_broadcast);
        csx_register_internal_call("Joy.Wsnetserver::wsnetserver_offline", (const void*)w_wsnetserver_offline);
        csx_register_internal_call("Joy.Wsnetserver::wsnetserver_update", (const void*)w_wsnetserver_update);
        csx_register_internal_call("Joy.Wsnetserver::wsnetserver_connection_count", (const void*)w_wsnetserver_connection_count);
        csx_register_internal_call("Joy.Wsnetserver::wsnetserver_poll_message", (const void*)w_wsnetserver_poll_message);
        csx_register_internal_call("Joy.Wsnetclient::wsnetclient_create", (const void*)w_wsnetclient_create);
        csx_register_internal_call("Joy.Wsnetclient::wsnetclient_destroy", (const void*)w_wsnetclient_destroy);
        csx_register_internal_call("Joy.Wsnetclient::wsnetclient_send", (const void*)w_wsnetclient_send);
        csx_register_internal_call("Joy.Wsnetclient::wsnetclient_update", (const void*)w_wsnetclient_update);
        csx_register_internal_call("Joy.Wsnetclient::wsnetclient_poll_message", (const void*)w_wsnetclient_poll_message);
        csx_register_internal_call("Joy.Netclient::netclient_destroy", (const void*)w_netclient_destroy);
        csx_register_internal_call("Joy.Netclient::netclient_send", (const void*)w_netclient_send);
        csx_register_internal_call("Joy.Netclient::netclient_update", (const void*)w_netclient_update);
        csx_register_internal_call("Joy.Netclient::netclient_poll_message", (const void*)w_netclient_poll_message);
        csx_register_internal_call("Joy.Netserver::netserver_destroy", (const void*)w_netserver_destroy);
        csx_register_internal_call("Joy.Netserver::netserver_send", (const void*)w_netserver_send);
        csx_register_internal_call("Joy.Netserver::netserver_broadcast", (const void*)w_netserver_broadcast);
        csx_register_internal_call("Joy.Netserver::netserver_offline", (const void*)w_netserver_offline);
        csx_register_internal_call("Joy.Netserver::netserver_update", (const void*)w_netserver_update);
        csx_register_internal_call("Joy.Netserver::netserver_connection_count", (const void*)w_netserver_connection_count);
        csx_register_internal_call("Joy.Netserver::netserver_poll_message", (const void*)w_netserver_poll_message);
        csx_register_internal_call("Joy.Netmessage::netmessage_free_data", (const void*)w_netmessage_free_data);
        csx_register_internal_call("Joy.Scene::scene_node_create", (const void*)w_scene_node_create);
        csx_register_internal_call("Joy.Scene::scene_node_destroy", (const void*)w_scene_node_destroy);
        csx_register_internal_call("Joy.Scene::scene_node_add_child", (const void*)w_scene_node_add_child);
        csx_register_internal_call("Joy.Scene::scene_node_remove_child", (const void*)w_scene_node_remove_child);
        csx_register_internal_call("Joy.Scene::scene_node_get_parent", (const void*)w_scene_node_get_parent);
        csx_register_internal_call("Joy.Scene::scene_node_get_first_child", (const void*)w_scene_node_get_first_child);
        csx_register_internal_call("Joy.Scene::scene_node_get_next_sibling", (const void*)w_scene_node_get_next_sibling);
        csx_register_internal_call("Joy.Scene::scene_node_get_child_count", (const void*)w_scene_node_get_child_count);
        csx_register_internal_call("Joy.Scene::scene_node_set_position", (const void*)w_scene_node_set_position);
        csx_register_internal_call("Joy.Scene::scene_node_set_world_position", (const void*)w_scene_node_set_world_position);
        csx_register_internal_call("Joy.Scene::scene_node_set_rotation", (const void*)w_scene_node_set_rotation);
        csx_register_internal_call("Joy.Scene::scene_node_get_rotation", (const void*)w_scene_node_get_rotation);
        csx_register_internal_call("Joy.Scene::scene_node_set_scale", (const void*)w_scene_node_set_scale);
        csx_register_internal_call("Joy.Scene::scene_node_set_zorder", (const void*)w_scene_node_set_zorder);
        csx_register_internal_call("Joy.Scene::scene_node_get_zorder", (const void*)w_scene_node_get_zorder);
        csx_register_internal_call("Joy.Scene::scene_node_set_userdata", (const void*)w_scene_node_set_userdata);
        csx_register_internal_call("Joy.Scene::scene_node_get_userdata", (const void*)w_scene_node_get_userdata);
        csx_register_internal_call("Joy.Scene::scene_node_set_name", (const void*)w_scene_node_set_name);
        csx_register_internal_call("Joy.Scene::scene_node_set_tag", (const void*)w_scene_node_set_tag);
        csx_register_internal_call("Joy.Scene::scene_find_node_by_name", (const void*)w_scene_find_node_by_name);
        csx_register_internal_call("Joy.Scene::scene_find_node_by_name_deep", (const void*)w_scene_find_node_by_name_deep);
        csx_register_internal_call("Joy.Scene::scene_node_handle_event", (const void*)w_scene_node_handle_event);
        csx_register_internal_call("Joy.Scene::scene_node_update", (const void*)w_scene_node_update);
        csx_register_internal_call("Joy.Scene::scene_node_render", (const void*)w_scene_node_render);
        csx_register_internal_call("Joy.Scene::scene_create", (const void*)w_scene_create);
        csx_register_internal_call("Joy.Scene::scene_destroy", (const void*)w_scene_destroy);
        csx_register_internal_call("Joy.Scene::scene_add_root_node", (const void*)w_scene_add_root_node);
        csx_register_internal_call("Joy.Scene::scene_remove_root_node", (const void*)w_scene_remove_root_node);
        csx_register_internal_call("Joy.Scene::scene_get_root_count", (const void*)w_scene_get_root_count);
        csx_register_internal_call("Joy.Scene::scene_get_root_at", (const void*)w_scene_get_root_at);
        csx_register_internal_call("Joy.Scene::scene_update", (const void*)w_scene_update);
        csx_register_internal_call("Joy.Scene::scene_render", (const void*)w_scene_render);
        csx_register_internal_call("Joy.Scene::scene_handle_event", (const void*)w_scene_handle_event);
        csx_register_internal_call("Joy.Scene::scene_set_popup_node", (const void*)w_scene_set_popup_node);
        csx_register_internal_call("Joy.Scene::scene_get_popup_node", (const void*)w_scene_get_popup_node);
        csx_register_internal_call("Joy.Scene::scene_set_userdata", (const void*)w_scene_set_userdata);
        csx_register_internal_call("Joy.Scene::scene_get_userdata", (const void*)w_scene_get_userdata);
        csx_register_internal_call("Joy.Scene::scene_manager_create", (const void*)w_scene_manager_create);
        csx_register_internal_call("Joy.Scene::scene_manager_destroy", (const void*)w_scene_manager_destroy);
        csx_register_internal_call("Joy.Scene::scene_manager_push", (const void*)w_scene_manager_push);
        csx_register_internal_call("Joy.Scene::scene_manager_replace", (const void*)w_scene_manager_replace);
        csx_register_internal_call("Joy.Scene::scene_manager_pop", (const void*)w_scene_manager_pop);
        csx_register_internal_call("Joy.Scene::scene_manager_update", (const void*)w_scene_manager_update);
        csx_register_internal_call("Joy.Scene::scene_manager_render", (const void*)w_scene_manager_render);
        csx_register_internal_call("Joy.Scene::scene_manager_handle_event", (const void*)w_scene_manager_handle_event);
        csx_register_internal_call("Joy.Scene::scene_manager_get_current", (const void*)w_scene_manager_get_current);
        csx_register_internal_call("Joy.Scene::scene_manager_get_count", (const void*)w_scene_manager_get_count);
        csx_register_internal_call("Joy.Jparticle::jparticle_destroy", (const void*)w_jparticle_destroy);
        csx_register_internal_call("Joy.Jparticle::jparticle_set_position", (const void*)w_jparticle_set_position);
        csx_register_internal_call("Joy.Jparticle::jparticle_emit", (const void*)w_jparticle_emit);
        csx_register_internal_call("Joy.Jparticle::jparticle_clear", (const void*)w_jparticle_clear);
        csx_register_internal_call("Joy.Jparticle::jparticle_update", (const void*)w_jparticle_update);
        csx_register_internal_call("Joy.Jparticle::jparticle_render", (const void*)w_jparticle_render);
        csx_register_internal_call("Joy.Jparticle::jparticle_count", (const void*)w_jparticle_count);
        csx_register_internal_call("Joy.Jparticle::jparticle_is_active", (const void*)w_jparticle_is_active);
        csx_register_internal_call("Joy.Jlight::jlight_sys_create", (const void*)w_jlight_sys_create);
        csx_register_internal_call("Joy.Jlight::jlight_sys_destroy", (const void*)w_jlight_sys_destroy);
        csx_register_internal_call("Joy.Jlight::jlight_sys_resize", (const void*)w_jlight_sys_resize);
        csx_register_internal_call("Joy.Jlight::jlight_remove", (const void*)w_jlight_remove);
        csx_register_internal_call("Joy.Jlight::jlight_clear", (const void*)w_jlight_clear);
        csx_register_internal_call("Joy.Jlight::jlight_add_occluder", (const void*)w_jlight_add_occluder);
        csx_register_internal_call("Joy.Jlight::jlight_clear_occluders", (const void*)w_jlight_clear_occluders);
        csx_register_internal_call("Joy.Jlight::jlight_render", (const void*)w_jlight_render);
        csx_register_internal_call("Joy.Jecs::jecs_create", (const void*)w_jecs_create);
        csx_register_internal_call("Joy.Jecs::jecs_destroy", (const void*)w_jecs_destroy);
        csx_register_internal_call("Joy.Jecs::jecs_process", (const void*)w_jecs_process);
        csx_register_internal_call("Joy.Jecs::jecs_define", (const void*)w_jecs_define);
        csx_register_internal_call("Joy.Audio::audio_open_device", (const void*)w_audio_open_device);
        csx_register_internal_call("Joy.Audio::audio_close_device", (const void*)w_audio_close_device);
        csx_register_internal_call("Joy.Audio::audio_create_wav", (const void*)w_audio_create_wav);
        csx_register_internal_call("Joy.Audio::audio_create_mp3", (const void*)w_audio_create_mp3);
        csx_register_internal_call("Joy.Audio::audio_create_flac", (const void*)w_audio_create_flac);
        csx_register_internal_call("Joy.Audio::audio_create_ogg", (const void*)w_audio_create_ogg);
        csx_register_internal_call("Joy.Audio::audio_shot_create", (const void*)w_audio_shot_create);
        csx_register_internal_call("Joy.Audio::audio_shot_create_mp3", (const void*)w_audio_shot_create_mp3);
        csx_register_internal_call("Joy.Audio::audio_shot_create_flac", (const void*)w_audio_shot_create_flac);
        csx_register_internal_call("Joy.Audio::audio_shot_create_ogg", (const void*)w_audio_shot_create_ogg);
        csx_register_internal_call("Joy.Audio::audio_shot_play", (const void*)w_audio_shot_play);
        csx_register_internal_call("Joy.Audio::audio_shot_set_gain", (const void*)w_audio_shot_set_gain);
        csx_register_internal_call("Joy.Audio::audio_shot_destroy", (const void*)w_audio_shot_destroy);
        csx_register_internal_call("Joy.Audio::audio_bgm_create", (const void*)w_audio_bgm_create);
        csx_register_internal_call("Joy.Audio::audio_bgm_create_mp3", (const void*)w_audio_bgm_create_mp3);
        csx_register_internal_call("Joy.Audio::audio_bgm_create_flac", (const void*)w_audio_bgm_create_flac);
        csx_register_internal_call("Joy.Audio::audio_bgm_create_ogg", (const void*)w_audio_bgm_create_ogg);
        csx_register_internal_call("Joy.Audio::audio_bgm_stop", (const void*)w_audio_bgm_stop);
        csx_register_internal_call("Joy.Audio::audio_bgm_set_gain", (const void*)w_audio_bgm_set_gain);
        csx_register_internal_call("Joy.Audio::audio_bgm_destroy", (const void*)w_audio_bgm_destroy);
}
