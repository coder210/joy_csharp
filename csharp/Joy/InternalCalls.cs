// 自动生成，勿手改：tools/gen_csclib.js
using System;
using System.Runtime.CompilerServices;

namespace Joy
{
    internal static class Animation
    {
        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr animation_create(IntPtr r2d);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void animation_destroy(IntPtr animation);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern bool animation_is_finished(IntPtr animation);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void animation_reset(IntPtr animation);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void animation_set_position(IntPtr animation, float x, float y);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void animation_set_rotation(IntPtr animation, float rotation);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void animation_set_scale(IntPtr animation, float x, float y);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void animation_update(IntPtr animation, float dt);

    }

    internal static class Audio
    {
        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr audio_bgm_create(string wav_path, uint device_id);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr audio_bgm_create_flac(string path, uint device_id);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr audio_bgm_create_mp3(string path, uint device_id);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr audio_bgm_create_ogg(string path, uint device_id);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void audio_bgm_destroy(IntPtr bgm);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void audio_bgm_set_gain(IntPtr bgm, float gain);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void audio_bgm_stop(IntPtr bgm);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void audio_close_device(uint device_id);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern bool audio_create_flac(string filepath, uint device_id);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern bool audio_create_mp3(string filepath, uint device_id);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern bool audio_create_ogg(string filepath, uint device_id);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern bool audio_create_wav(string filepath, uint device_id);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern uint audio_open_device();

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr audio_shot_create(string wav_path, uint device_id);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr audio_shot_create_flac(string path, uint device_id);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr audio_shot_create_mp3(string path, uint device_id);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr audio_shot_create_ogg(string path, uint device_id);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void audio_shot_destroy(IntPtr shot);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void audio_shot_play(IntPtr shot);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void audio_shot_set_gain(IntPtr shot, float gain);

    }

    internal static class Button
    {
        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr button_create(IntPtr r2d, float cx, float cy, float wf, float hf);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void button_destroy(IntPtr btn);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void button_draw(IntPtr btn);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern bool button_get_pressed(IntPtr btn);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern bool button_is_hovered(IntPtr btn, float x, float y);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern bool button_is_pressed(IntPtr btn, float x, float y);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void button_process_event(IntPtr btn, IntPtr @event);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void button_set_hovered(IntPtr btn, bool v);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void button_set_image(IntPtr btn, IntPtr image);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void button_set_position(IntPtr btn, float x, float y);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void button_set_pressed(IntPtr btn, bool v);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void button_set_pressed_image(IntPtr btn, IntPtr image);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void button_set_size(IntPtr btn, float width, float height);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void button_set_text_offset(IntPtr btn, float x, float y);

    }

    internal static class Checkbox
    {
        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr checkbox_create(float fx, float fy, float size_frac, string label);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void checkbox_destroy(IntPtr checkbox);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void checkbox_draw(IntPtr cb, IntPtr r2d, IntPtr font);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern bool checkbox_is_pressed(IntPtr cb, float x, float y);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void checkbox_process_event(IntPtr cb, IntPtr @event);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void checkbox_set_hovered(IntPtr cb, bool v);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void checkbox_set_position(IntPtr checkbox, int x, int y);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void checkbox_set_r2d(IntPtr checkbox, IntPtr r2d);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void checkbox_toggle(IntPtr checkbox);

    }

    internal static class Combobox
    {
        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr combobox_create(IntPtr r2d, float fx, float fy, float fw, float fh);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void combobox_destroy(IntPtr combobox);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void combobox_draw(IntPtr combobox);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern int combobox_get_selected(IntPtr combobox);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern int combobox_hit_item(IntPtr combobox, float x, float y);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void combobox_input_add_item(IntPtr ci, string str, int len);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void combobox_input_clear_items(IntPtr ci);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr combobox_input_create(IntPtr r2d, float fx, float fy, float fw, float fh, IntPtr font, int buf_len);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void combobox_input_destroy(IntPtr ci);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void combobox_input_draw(IntPtr ci);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void combobox_input_draw_dropdown(IntPtr ci);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern int combobox_input_hit_item(IntPtr ci, float x, float y);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern bool combobox_input_is_open(IntPtr ci);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void combobox_input_process_event(IntPtr ci, IntPtr ev);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void combobox_input_set_open(IntPtr ci, bool v);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void combobox_input_set_popup_node(IntPtr ci, IntPtr node);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void combobox_input_set_text(IntPtr ci, string str);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern bool combobox_is_open(IntPtr combobox);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern bool combobox_is_pressed(IntPtr combobox, float x, float y);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void combobox_process_event(IntPtr cb, IntPtr @event);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void combobox_set_open(IntPtr combobox, bool v);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void combobox_set_selected(IntPtr combobox, int index);

    }

    internal static class Create
    {
        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr create_window(string title, int w, int h);

    }

    internal static class Datagrid
    {
        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr datagrid_create(IntPtr r2d, float fx, float fy, float fw, float fh, int col_count, bool has_header, IntPtr font);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void datagrid_destroy(IntPtr grid);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void datagrid_draw(IntPtr grid, IntPtr r2d);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern int datagrid_hit_row(IntPtr grid, float x, float y);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void datagrid_process_event(IntPtr dg, IntPtr @event);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void datagrid_scroll(IntPtr grid, int lines);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void datagrid_set_selected_row(IntPtr grid, int row);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void datagrid_setcell(IntPtr grid, int row_index, int col_index, string data);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void datagrid_setheader(IntPtr grid, int index, string header);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void datagrid_setheaders(IntPtr grid, string headers);

    }

    internal static class Destroy
    {
        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void destroy_window(IntPtr win);

    }

    internal static class Env
    {
        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr env_create();

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void env_destroy(IntPtr env);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void env_set(IntPtr env, string key, string value);

    }

    internal static class Font
    {
        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr font_create(string filename, int fontsize);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void font_destroy(IntPtr font);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern int font_get_ascent(IntPtr font);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern float font_get_scale(IntPtr font);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern int font_get_size(IntPtr font);

    }

    internal static class Game
    {
        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern float game_timer_get_delta_time(IntPtr clock);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern int game_timer_get_target_fps(IntPtr clock);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern float game_timer_get_time_scale(IntPtr clock);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern float game_timer_get_unscaled_delta_time(IntPtr clock);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void game_timer_init(IntPtr clock);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void game_timer_set_target_fps(IntPtr clock, int fps);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void game_timer_set_time_scale(IntPtr clock, float scale);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void game_timer_update(IntPtr clock);

    }

    internal static class Get
    {
        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern int get_event_code(IntPtr @event);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern int get_event_type(IntPtr @event);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern int get_mouse_button(IntPtr @event);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr get_raw_window(IntPtr win);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern ulong get_ticks();

    }

    internal static class Image
    {
        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr image_create(IntPtr r2d, string filename);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr image_create_empty(IntPtr r2d, int w, int h);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr image_create_from_data(IntPtr r2d, IntPtr rgba_pixels, int w, int h);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void image_destroy(IntPtr image);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void image_set_blend_mode(IntPtr image, int mode);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void image_set_scale_mode(IntPtr image, int nearest);

    }

    internal static class Init
    {
        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern bool init_env();

    }

    internal static class Inputbox
    {
        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void inputbox_backspace(IntPtr ti);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void inputbox_blur(IntPtr ti);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void inputbox_copy(IntPtr ti);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr inputbox_create(IntPtr r2d, float fx, float fy, float fw, float fh, IntPtr font);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void inputbox_cursor_end(IntPtr ti);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void inputbox_cursor_home(IntPtr ti);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void inputbox_cursor_left(IntPtr ti);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void inputbox_cursor_right(IntPtr ti);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void inputbox_cut(IntPtr ti);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void inputbox_defocus(IntPtr ti);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void inputbox_delete(IntPtr ti);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void inputbox_destroy(IntPtr ti);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void inputbox_draw(IntPtr ti);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void inputbox_focus(IntPtr ti);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void inputbox_insert(IntPtr ti, string s, int len);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern bool inputbox_is_focused(IntPtr ti);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern bool inputbox_is_hovered(IntPtr ti, float x, float y);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern bool inputbox_is_pressed(IntPtr ti, float x, float y);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void inputbox_paste(IntPtr ti);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void inputbox_process_event(IntPtr ti, IntPtr @event);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void inputbox_select_all(IntPtr ti);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void inputbox_select_end(IntPtr ti);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void inputbox_select_home(IntPtr ti);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void inputbox_select_left(IntPtr ti);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void inputbox_select_right(IntPtr ti);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void inputbox_set_text(IntPtr ti, string text);

    }

    internal static class Iocp
    {
        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void iocp_process_events(IntPtr server, int timeout_ms);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr iocp_server_create(string bind_ip, int bind_port);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void iocp_server_destroy(IntPtr server);

    }

    internal static class Is
    {
        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern bool is_user_event(IntPtr @event, int type);

    }

    internal static class Janimator
    {
        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern int janimator_add_any_transition(IntPtr anim, string to);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void janimator_add_state(IntPtr anim, string name);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern int janimator_add_transition(IntPtr anim, string from, string to);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr janimator_create(IntPtr r2d);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void janimator_destroy(IntPtr anim);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void janimator_draw(IntPtr anim, float x, float y);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern bool janimator_get_bool(IntPtr anim, string name);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern float janimator_get_float(IntPtr anim, string name);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern int janimator_get_int(IntPtr anim, string name);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void janimator_set_bool(IntPtr anim, string name, bool v);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void janimator_set_default_state(IntPtr anim, string name);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void janimator_set_flip_h(IntPtr anim, bool flip);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void janimator_set_float(IntPtr anim, string name, float v);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void janimator_set_int(IntPtr anim, string name, int v);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void janimator_set_trigger(IntPtr anim, string name);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void janimator_state_set_blend(IntPtr anim, string state_name, string param_name);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void janimator_state_set_loop(IntPtr anim, string state_name, bool loop);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void janimator_state_set_speed(IntPtr anim, string state_name, float speed);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void janimator_transition_add_cond(IntPtr anim, int trans_idx, string param_name, int mode, float threshold);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void janimator_transition_set_exit_time(IntPtr anim, int trans_idx, float seconds);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void janimator_update(IntPtr anim, float dt);

    }

    internal static class Jecs
    {
        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr jecs_create();

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void jecs_define(IntPtr world, string name, nuint size);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void jecs_destroy(IntPtr world);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void jecs_process(IntPtr world, float dt);

    }

    internal static class Jlight
    {
        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern int jlight_add_occluder(IntPtr sys, float x1, float y1, float x2, float y2);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void jlight_clear(IntPtr sys);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void jlight_clear_occluders(IntPtr sys);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void jlight_remove(IntPtr sys, int id);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void jlight_render(IntPtr sys, IntPtr r2d);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr jlight_sys_create(int width, int height);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void jlight_sys_destroy(IntPtr sys);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void jlight_sys_resize(IntPtr sys, int width, int height);

    }

    internal static class Joystick
    {
        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr joystick_create(IntPtr r2d, float cx, float cy, float radius_frac);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void joystick_destroy(IntPtr joystick);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void joystick_draw(IntPtr joystick);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern float joystick_get_magnitude(IntPtr joystick);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern bool joystick_is_dragging(IntPtr joystick);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void joystick_process_event(IntPtr js, IntPtr @event);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void joystick_reset(IntPtr joystick);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void joystick_set_position(IntPtr joystick, float x, float y);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void joystick_set_radius(IntPtr joystick, float radius);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void joystick_set_textures(IntPtr joystick, string base_path, string thumb_path);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void joystick_set_vector(IntPtr joystick, float dx, float dy);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void joystick_touch_down(IntPtr joystick, float x, float y);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void joystick_touch_move(IntPtr joystick, float x, float y);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void joystick_touch_up(IntPtr joystick);

    }

    internal static class Jparticle
    {
        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void jparticle_clear(IntPtr p);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern int jparticle_count(IntPtr p);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void jparticle_destroy(IntPtr p);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void jparticle_emit(IntPtr p);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern bool jparticle_is_active(IntPtr p);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void jparticle_render(IntPtr p, IntPtr r2d);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void jparticle_set_position(IntPtr p, float x, float y);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void jparticle_update(IntPtr p, float dt);

    }

    internal static class Jpm
    {
        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void jpm_config_add_spawn(IntPtr cfg, int cx10, int cz10, int radius10);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern uint jpm_wave_seed(uint base_seed, int wave);

    }

    internal static class Jtext
    {
        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void jtext_cache_clear();

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern int jtext_cache_get_count();

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void jtext_cache_set_limit(int max_entries);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void jtext_cache_sweep(int max_idle_frames);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void jtext_print(IntPtr r2d, IntPtr jtext_tex, float x, float y);

    }

    internal static class Jtilemap
    {
        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void jtilemap_destroy(IntPtr tm);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr jtilemap_find_object_layer(IntPtr tm, string name);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr jtilemap_find_tile_layer(IntPtr tm, string name);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern int jtilemap_get_anim_tileid(IntPtr tm, int gid, uint time_ms);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern int jtilemap_get_height(IntPtr tm);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern int jtilemap_get_tile(IntPtr layer, int tx, int ty);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern int jtilemap_get_tileheight(IntPtr tm);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern int jtilemap_get_tilewidth(IntPtr tm);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern int jtilemap_get_width(IntPtr tm);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr jtilemap_load_file_json(string filename);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void jtilemap_render_all(IntPtr r, IntPtr tm, float camera_x, float camera_y, uint time_ms);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void jtilemap_render_destroy(IntPtr r);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern bool jtilemap_render_layer(IntPtr r, IntPtr tm, string layer_name, float camera_x, float camera_y, uint time_ms);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void jtilemap_render_set_tile_px(IntPtr r, float px);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void jtilemap_render_tiles(IntPtr r, IntPtr tm, float camera_x, float camera_y, uint time_ms);

    }

    internal static class Jtimer
    {
        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void jtimer_destroy(IntPtr timer);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern ulong jtimer_get_elapsed(IntPtr timer);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void jtimer_reset(IntPtr timer);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void jtimer_set_active(IntPtr timer, bool active);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void jtimer_set_interval(IntPtr timer, int interval);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void jtimer_trigger(IntPtr timer);

    }

    internal static class Jui
    {
        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void jui_begin(IntPtr ctx);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr jui_ctx_create(IntPtr r2d, IntPtr font);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void jui_ctx_destroy(IntPtr ctx);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void jui_end(IntPtr ctx);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void jui_input_down(IntPtr ctx, int button);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void jui_input_key(IntPtr ctx, bool shift, bool ctrl);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void jui_input_motion(IntPtr ctx, float win_x, float win_y);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void jui_input_up(IntPtr ctx, int button);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void jui_input_wheel(IntPtr ctx, float dy);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern bool jui_is_ctrl(IntPtr ctx);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern bool jui_is_down(IntPtr ctx);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern bool jui_is_pressed(IntPtr ctx);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern bool jui_is_released(IntPtr ctx);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern bool jui_is_shift(IntPtr ctx);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void jui_panel_end(IntPtr ctx);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void jui_pop_clip(IntPtr ctx);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void jui_reset_clip(IntPtr ctx);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void jui_scroll_end(IntPtr ctx);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void jui_scroll_set_offset(IntPtr ctx, int id, float off, float content_h, float view_h);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern float jui_take_wheel(IntPtr ctx);

    }

    internal static class Kcpclient
    {
        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr kcpclient_create(string ip, int port);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void kcpclient_destroy(IntPtr kc);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern bool kcpclient_poll_message(IntPtr kc, IntPtr msg);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern int kcpclient_send(IntPtr kc, string data, int len);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void kcpclient_update(IntPtr kc);

    }

    internal static class Kcpserver
    {
        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void kcpserver_broadcast(IntPtr ks, string data, int len);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern int kcpserver_connection_count(IntPtr ks);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr kcpserver_create(string ip, int port);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern int kcpserver_destroy(IntPtr ks);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void kcpserver_offline(IntPtr ks, int conv);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern bool kcpserver_poll_message(IntPtr ks, IntPtr msg);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void kcpserver_send(IntPtr ks, int conv, string data, int len);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void kcpserver_update(IntPtr ks);

    }

    internal static class Label
    {
        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void label_destroy(IntPtr label);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void label_draw(IntPtr label);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void label_process_event(IntPtr label, IntPtr @event);

    }

    internal static class Lcg
    {
        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr lcg_random_create(ulong seed);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void lcg_random_destroy(IntPtr lcg);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern uint lcg_random_next(IntPtr lcg);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void lcg_random_set_state(IntPtr lcg, ulong state);

    }

    internal static class Log
    {
        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void log_title(int type);

    }

    internal static class Netclient
    {
        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void netclient_destroy(IntPtr nc);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern bool netclient_poll_message(IntPtr nc, IntPtr msg);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern int netclient_send(IntPtr nc, string data, int len);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void netclient_update(IntPtr nc);

    }

    internal static class Netmessage
    {
        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void netmessage_free_data(IntPtr msg);

    }

    internal static class Netserver
    {
        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void netserver_broadcast(IntPtr ns, string data, int len);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern int netserver_connection_count(IntPtr ns);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void netserver_destroy(IntPtr ns);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void netserver_offline(IntPtr ns, int conv);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern bool netserver_poll_message(IntPtr ns, IntPtr msg);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void netserver_send(IntPtr ns, int conv, string data, int len);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void netserver_update(IntPtr ns);

    }

    internal static class Popup
    {
        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr popup_create(IntPtr r2d, float fw, float fh);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void popup_destroy(IntPtr p);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void popup_drag_move(IntPtr p, float mx, float my);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void popup_draw(IntPtr p, IntPtr title_font, IntPtr content_font);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern bool popup_is_close_clicked(IntPtr p, float mx, float my);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern bool popup_is_inside(IntPtr p, float mx, float my);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern bool popup_is_title_clicked(IntPtr p, float mx, float my);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void popup_process_event(IntPtr p, IntPtr @event);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void popup_set_closeable(IntPtr p, bool v);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void popup_set_content(IntPtr p, string text, int len);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void popup_set_position(IntPtr p, float x, float y);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void popup_set_title(IntPtr p, string text, int len);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void popup_set_visible(IntPtr p, bool v);

    }

    internal static class Push
    {
        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern bool push_quit_event();

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern bool push_user_event(int type, int code);

    }

    internal static class Quit
    {
        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void quit_env();

    }

    internal static class R2d
    {
        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void r2d_begin(IntPtr r2d);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void r2d_clear_clip(IntPtr r2d);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr r2d_create(IntPtr win);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void r2d_destroy(IntPtr r2d);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern bool r2d_draw_point(IntPtr r2d, float x, float y);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern bool r2d_draw_point_f(IntPtr r2d, float fx, float fy);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void r2d_end(IntPtr r2d);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern bool r2d_point_in_clip(IntPtr r2d, float x, float y);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void r2d_pop_clip_rect(IntPtr r2d);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void r2d_reset_clip_stack(IntPtr r2d);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern bool r2d_set_blend_mode(IntPtr r2d, int mode);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void r2d_set_colorf(IntPtr r2d, float r, float g, float b, float a);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern bool r2d_set_logical_presentation(IntPtr r2d, int w, int h);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern bool r2d_set_logical_presentation_mode(IntPtr r2d, int w, int h, int mode);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern bool r2d_set_scale(IntPtr r2d, float sx, float sy);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern bool r2d_set_vsync(IntPtr r2d, int vsync);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr r2d_unwrap(IntPtr r2d);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr r2d_wrap(IntPtr sdl_renderer);

    }

    internal static class R3d
    {
        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern bool r3d_begin(IntPtr r);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr r3d_button_create(float x, float y, float w, float h, string text);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void r3d_button_destroy(IntPtr btn);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void r3d_button_draw(IntPtr r, IntPtr m, IntPtr btn, float winW, float winH);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void r3d_button_draw_circle(IntPtr r, IntPtr m, IntPtr btn, float winW, float winH);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern bool r3d_button_is_hovered(IntPtr r, IntPtr btn, float mx, float my);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern bool r3d_button_is_pressed(IntPtr r, IntPtr btn, bool mouse_down, float mx, float my);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void r3d_button_release(IntPtr r, IntPtr btn, float mx, float my);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr r3d_checkbox_create(float x, float y, float size, string label);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void r3d_checkbox_destroy(IntPtr cb);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void r3d_checkbox_draw(IntPtr r, IntPtr m, IntPtr cb, float winW, float winH);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern bool r3d_checkbox_is_hovered(IntPtr r, IntPtr cb, float x, float y);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern bool r3d_checkbox_is_pressed(IntPtr r, IntPtr cb, float x, float y);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void r3d_checkbox_set_hovered(IntPtr cb, bool v);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void r3d_checkbox_toggle(IntPtr cb);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void r3d_combobox_input_add_item(IntPtr ci, string str);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void r3d_combobox_input_clear_items(IntPtr ci);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void r3d_combobox_input_destroy(IntPtr ci);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void r3d_combobox_input_draw(IntPtr r, IntPtr m, IntPtr ci, float winW, float winH);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void r3d_combobox_input_draw_dropdown(IntPtr r, IntPtr m, IntPtr ci, float winW, float winH);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern int r3d_combobox_input_hit_item(IntPtr ci, float x, float y);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void r3d_combobox_input_set_text(IntPtr ci, string str);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr r3d_create(IntPtr win, string shader_dir);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr r3d_create_depth_texture(IntPtr device, int width, int height);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr r3d_create_lighting_pipeline(IntPtr device, IntPtr vertex_shader, IntPtr fragment_shader, int swapchain_format, int depth_format);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr r3d_create_line_pipeline(IntPtr device, IntPtr vertex_shader, IntPtr fragment_shader, int swapchain_format, int depth_format);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr r3d_create_pipeline(IntPtr device, IntPtr vertex_shader, IntPtr fragment_shader, int swapchain_format, int depth_format);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr r3d_create_sampler(IntPtr device);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr r3d_create_texture(IntPtr r, int w, int h, IntPtr rgba32, int flip);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void r3d_destroy(IntPtr r);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void r3d_draw_grid(IntPtr r, int slices, float spacing, float line_width);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void r3d_draw_tex_2d(IntPtr r, IntPtr m, float x, float y, float w, float h, IntPtr tex, float winW, float winH);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void r3d_end(IntPtr r);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void r3d_font_cache_clear(IntPtr r);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern int r3d_font_cache_get_count(IntPtr r);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void r3d_font_cache_set_limit(IntPtr r, int max_entries);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void r3d_font_cache_sweep(IntPtr r, int max_idle_frames);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern bool r3d_font_draw_2d(IntPtr r, IntPtr m, string text, float pixelX, float pixelY, float fontSize, float winW, float winH);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern bool r3d_font_init(IntPtr r, string ttf_path, int pixel_height);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr r3d_gen_checkerboard(IntPtr r, int tile_size, int tile_count);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr r3d_get_device(IntPtr r);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern int r3d_get_draw_calls(IntPtr r);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void r3d_input_backspace(IntPtr inp);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void r3d_input_click(IntPtr r, IntPtr inp, float mx, float my);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void r3d_input_cursor_end(IntPtr inp);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void r3d_input_cursor_home(IntPtr inp);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void r3d_input_cursor_left(IntPtr inp);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void r3d_input_cursor_right(IntPtr inp);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void r3d_input_defocus(IntPtr inp);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void r3d_input_delete(IntPtr inp);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void r3d_input_destroy(IntPtr inp);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void r3d_input_draw(IntPtr r, IntPtr m, IntPtr inp, float winW, float winH);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void r3d_input_focus(IntPtr inp);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void r3d_input_insert(IntPtr inp, string s);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern bool r3d_input_is_focused(IntPtr inp);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern bool r3d_input_is_hovered(IntPtr r, IntPtr inp, float mx, float my);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void r3d_input_set_text(IntPtr inp, string text);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void r3d_input_start_text_input(IntPtr r, IntPtr inp);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void r3d_input_stop_text_input(IntPtr r, IntPtr inp);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void r3d_input_submit(IntPtr inp);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void r3d_label_destroy(IntPtr l);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void r3d_label_draw(IntPtr r, IntPtr m, IntPtr l, float winW, float winH);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void r3d_label_set_text(IntPtr l, string text);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr r3d_load_shader(IntPtr device, string filename, int stage, int sampler_num, int uniform_buffer_num);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr r3d_mesh_cube(IntPtr r, float w, float h, float d);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr r3d_mesh_cube_lit(IntPtr r, float w, float h, float d);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr r3d_mesh_cube_wire(IntPtr r, float w, float h, float d);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr r3d_mesh_custom(IntPtr r, IntPtr verts, int vertex_count);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr r3d_mesh_custom_lit(IntPtr r, IntPtr verts, int vertex_count);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void r3d_mesh_destroy(IntPtr r, IntPtr m);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr r3d_mesh_plane(IntPtr r, float w, float d, int segs);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr r3d_mesh_plane_lit(IntPtr r, float w, float d, int segs);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr r3d_mesh_plane_wire(IntPtr r, float w, float d, int segs);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr r3d_mesh_quad(IntPtr r);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr r3d_mesh_ramp(IntPtr r, float w, float l, float h);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr r3d_mesh_ramp_lit(IntPtr r, float w, float l, float h);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr r3d_mesh_ramp_wire(IntPtr r, float w, float l, float h);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr r3d_mesh_sphere(IntPtr r, float radius, int slices, int stacks);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr r3d_mesh_sphere_lit(IntPtr r, float radius, int slices, int stacks);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr r3d_mesh_sphere_wire(IntPtr r, float radius, int slices, int stacks);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void r3d_set_logical_presentation(IntPtr r, int w, int h);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void r3d_set_logical_presentation_mode(IntPtr r, int w, int h, int mode);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr r3d_slider_create(float x, float y, float w, float h, float min, float max, float initial);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void r3d_slider_destroy(IntPtr s);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void r3d_slider_drag_move(IntPtr r, IntPtr s, float x, float y);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void r3d_slider_draw(IntPtr r, IntPtr m, IntPtr s, float winW, float winH);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern float r3d_slider_get_value(IntPtr s);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern bool r3d_slider_is_hovered(IntPtr r, IntPtr s, float x, float y);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern bool r3d_slider_is_pressed(IntPtr r, IntPtr s, float x, float y);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void r3d_slider_set_hovered(IntPtr s, bool v);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void r3d_slider_set_pressed(IntPtr s, bool v);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void r3d_slider_set_value(IntPtr s, float v);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr r3d_upload_buffer(IntPtr device, IntPtr data, nuint size);

    }

    internal static class Radio
    {
        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr radio_create(float fx, float fy, float size_frac, string label, int group_id);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void radio_destroy(IntPtr radio);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern bool radio_is_pressed(IntPtr radio, float x, float y);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void radio_process_event(IntPtr rb, IntPtr @event);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void radio_set_hovered(IntPtr radio, bool v);

    }

    internal static class Scene
    {
        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void scene_add_root_node(IntPtr scene, IntPtr root);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr scene_create(string name);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void scene_destroy(IntPtr scene);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr scene_find_node_by_name(IntPtr root, string name);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr scene_find_node_by_name_deep(IntPtr scene, string name);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr scene_get_popup_node(IntPtr scene);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr scene_get_root_at(IntPtr scene, int index);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern int scene_get_root_count(IntPtr scene);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr scene_get_userdata(IntPtr scene);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void scene_handle_event(IntPtr scene, IntPtr e);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr scene_manager_create();

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void scene_manager_destroy(IntPtr mgr);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern int scene_manager_get_count(IntPtr mgr);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr scene_manager_get_current(IntPtr mgr);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void scene_manager_handle_event(IntPtr mgr, IntPtr e);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void scene_manager_pop(IntPtr mgr);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void scene_manager_push(IntPtr mgr, IntPtr scene);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void scene_manager_render(IntPtr mgr, IntPtr arg);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void scene_manager_replace(IntPtr mgr, IntPtr scene);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void scene_manager_update(IntPtr mgr, float delta_time);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void scene_node_add_child(IntPtr parent, IntPtr child);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr scene_node_create();

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void scene_node_destroy(IntPtr node);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern int scene_node_get_child_count(IntPtr node);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr scene_node_get_first_child(IntPtr node);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr scene_node_get_next_sibling(IntPtr node);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr scene_node_get_parent(IntPtr node);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern float scene_node_get_rotation(IntPtr node);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr scene_node_get_userdata(IntPtr node);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern int scene_node_get_zorder(IntPtr node);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void scene_node_handle_event(IntPtr node, IntPtr e);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void scene_node_remove_child(IntPtr parent, IntPtr child);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void scene_node_render(IntPtr node, IntPtr arg);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void scene_node_set_name(IntPtr node, string name);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void scene_node_set_position(IntPtr node, float x, float y);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void scene_node_set_rotation(IntPtr node, float radians);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void scene_node_set_scale(IntPtr node, float scale_x, float scale_y);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void scene_node_set_tag(IntPtr node, string tag);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void scene_node_set_userdata(IntPtr node, IntPtr userdata);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void scene_node_set_world_position(IntPtr node, float x, float y);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void scene_node_set_zorder(IntPtr node, int zorder);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void scene_node_update(IntPtr node, float delta_time);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void scene_remove_root_node(IntPtr scene, IntPtr root);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void scene_render(IntPtr scene, IntPtr arg);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void scene_set_popup_node(IntPtr scene, IntPtr node);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void scene_set_userdata(IntPtr scene, IntPtr ud);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void scene_update(IntPtr scene, float delta_time);

    }

    internal static class Scrollview
    {
        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void scrollview_begin(IntPtr v);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void scrollview_clamp(IntPtr v);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr scrollview_create(IntPtr r2d, float fx, float fy, float fw, float fh);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void scrollview_destroy(IntPtr v);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern bool scrollview_dragging(IntPtr v);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void scrollview_end(IntPtr v);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern float scrollview_get_offset_x(IntPtr v);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern float scrollview_get_offset_y(IntPtr v);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern bool scrollview_hit(IntPtr v, float win_x, float win_y);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern bool scrollview_process_event(IntPtr v, IntPtr @event);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void scrollview_set_content(IntPtr v, float content_w, float content_h);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void scrollview_set_offset(IntPtr v, float ox, float oy);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void scrollview_set_show_bar(IntPtr v, bool show);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void scrollview_set_view_px(IntPtr v, float x, float y, float w, float h);

    }

    internal static class Set
    {
        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void set_clipboard_text(string text);

    }

    internal static class Shape
    {
        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern bool shape_draw_line(IntPtr r2d, float x1, float y1, float x2, float y2);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern bool shape_draw_line_f(IntPtr r2d, float fx1, float fy1, float fx2, float fy2);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern bool shape_draw_rectangle_f(IntPtr r2d, string mode, float fx, float fy, float fw, float fh);

    }

    internal static class Should
    {
        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern bool should_close(IntPtr ev);

    }

    internal static class Simple
    {
        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr simple_fps_create();

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void simple_fps_destory(IntPtr fps);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void simple_fps_update(IntPtr fps);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern int simple_fps_value(IntPtr fps);

    }

    internal static class Slider
    {
        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr slider_create(IntPtr r2d, float fx, float fy, float fw, float fh, float min, float max, float initial);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void slider_destroy(IntPtr s);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void slider_drag_move(IntPtr s, float x, float y);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void slider_draw(IntPtr s);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern float slider_get_value(IntPtr s);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern bool slider_is_hovered(IntPtr s, float x, float y);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern bool slider_is_pressed(IntPtr s, float x, float y);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void slider_process_event(IntPtr s, IntPtr @event);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void slider_set_hovered(IntPtr s, bool v);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void slider_set_pressed(IntPtr s, bool v);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void slider_set_range(IntPtr s, float min, float max);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void slider_set_rect(IntPtr s, float x, float y, float w, float h);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void slider_set_value(IntPtr s, float v);

    }

    internal static class Sys
    {
        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern int sys_anyaddr();

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern bool sys_bind(long sockfd, string ip, int port);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern bool sys_closesocket(long sockfd);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern bool sys_connect(long sockfd, string ip, int port);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern long sys_current_time();

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern bool sys_init_netenv();

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void sys_install_crash_handlers();

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern bool sys_listen(long sockfd);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern bool sys_release_netenv();

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern int sys_send(long sockfd, string buf, int len);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern int sys_sendto(long sockfd, string buf, int len, string ip, int port);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern int sys_set_sock_accpettimeo(long sockfd, int ms);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern int sys_set_sock_broadcast(long sockfd);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern int sys_set_sock_rcvtimeo(long sockfd, int ms);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern int sys_set_sock_reuseaddr(long sockfd);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern int sys_set_sock_sndtimeo(long sockfd, int ms);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void sys_sleep(int ms);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern long sys_tcp();

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern long sys_udp();

    }

    internal static class Tcpclient
    {
        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr tcpclient_create(string ip, int port);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void tcpclient_destroy(IntPtr tcpclient);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern bool tcpclient_poll_message(IntPtr tcpclient, IntPtr msg);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern int tcpclient_send(IntPtr tcpclient, string data, int len);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void tcpclient_update(IntPtr tcpclient);

    }

    internal static class Tcpserver
    {
        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void tcpserver_broadcast(IntPtr tcpserver, string data, int len);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern int tcpserver_connection_count(IntPtr tcpserver);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr tcpserver_create(string ip, int port);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern int tcpserver_destroy(IntPtr tcpserver);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void tcpserver_offline(IntPtr tcpserver, int conv);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern bool tcpserver_poll_message(IntPtr tcpserver, IntPtr msg);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void tcpserver_send(IntPtr tcpserver, int conv, string data, int len);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void tcpserver_update(IntPtr tcpserver);

    }

    internal static class Text
    {
        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void text_destroy(IntPtr jtext_tex);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern int text_get_height(IntPtr jtext_tex);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern int text_get_width(IntPtr jtext_tex);

    }

    internal static class Tooltip
    {
        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr tooltip_create(IntPtr r2d, string text, int len);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void tooltip_destroy(IntPtr t);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void tooltip_draw(IntPtr t, IntPtr font);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void tooltip_process_event(IntPtr t, IntPtr @event);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void tooltip_set_position(IntPtr t, float x, float y);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void tooltip_set_text(IntPtr t, string text, int len);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void tooltip_set_visible(IntPtr t, bool v);

    }

    internal static class Window
    {
        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern bool window_get_fullscreen(IntPtr win);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void window_set_fullscreen(IntPtr win, bool fullscreen);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void window_set_icon(IntPtr win, string png_path);

    }

    internal static class Wsnetclient
    {
        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr wsnetclient_create(string url);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void wsnetclient_destroy(IntPtr wc);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern bool wsnetclient_poll_message(IntPtr wc, IntPtr msg);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern int wsnetclient_send(IntPtr wc, string data, int len);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void wsnetclient_update(IntPtr wc);

    }

    internal static class Wsnetserver
    {
        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void wsnetserver_broadcast(IntPtr ws, string data, int len);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern int wsnetserver_connection_count(IntPtr ws);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr wsnetserver_create(string ip, int port);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern int wsnetserver_destroy(IntPtr ws);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void wsnetserver_offline(IntPtr ws, int conv);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern bool wsnetserver_poll_message(IntPtr ws, IntPtr msg);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void wsnetserver_send(IntPtr ws, int conv, string data, int len);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void wsnetserver_update(IntPtr ws);

    }

}
