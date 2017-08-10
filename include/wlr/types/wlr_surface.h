#ifndef _WLR_TYPES_WLR_SURFACE_H
#define _WLR_TYPES_WLR_SURFACE_H
#include <wayland-server.h>
#include <pixman.h>
#include <stdint.h>

struct wlr_frame_callback {
	struct wl_resource *resource;
	struct wl_list link;
};

#define WLR_SURFACE_INVALID_BUFFER 1
#define WLR_SURFACE_INVALID_SURFACE_DAMAGE 2
#define WLR_SURFACE_INVALID_BUFFER_DAMAGE 4
#define WLR_SURFACE_INVALID_OPAQUE_REGION 8
#define WLR_SURFACE_INVALID_INPUT_REGION 16
#define WLR_SURFACE_INVALID_TRANSFORM 16
#define WLR_SURFACE_INVALID_SCALE 16

struct wlr_surface_state {
	uint32_t invalid;
	struct wl_resource *buffer;
	int32_t sx, sy;
	pixman_region32_t surface_damage, buffer_damage;
	pixman_region32_t opaque, input;
	uint32_t transform;
	int32_t scale;
};

struct wlr_surface {
	struct wl_resource *resource;
	struct wlr_texture *texture;
	struct wlr_surface_state current, pending;
	const char *role; // the lifetime-bound role or null

	float buffer_to_surface_matrix[16];
	float surface_to_buffer_matrix[16];

	struct {
		struct wl_signal destroy;
		struct wl_signal commit;
	} signals;

	struct wl_list frame_callback_list; // wl_surface.frame
};

struct wlr_renderer;
struct wlr_surface *wlr_surface_create(struct wl_resource *res,
		struct wlr_renderer *renderer);

#endif