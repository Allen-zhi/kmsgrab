#include<stdio.h>

void kmssink(int drm_fd, int dma_fd, int bpp, int width, int height, int pitch)
{
    int handle;
    drmPrimeFDToHandle(drm_fd, dma_fd, &handle);
    printf("drm handle: %d\n", handle);

    int fb;
    drmModeAddFB(drm_fd, width, height, bpp, bpp, pitch, handle, &fb);
    printf("drm fb: %d\n", fb);

    int plane_id = atoi(getenv("PLANE_ID"));
    int crtc_id = atoi(getenv("CRTC_ID"));
    int crtc_w = width / 2;//atoi(getenv("CRTC_W"));
    int crtc_h = height / 2;//atoi(getenv("CRTC_H"));
    while (1)
    drmModeSetPlane(drm_fd, plane_id, crtc_id, fb, 0, 0, 0, width, height, 0, 0, crtc_w << 16, crtc_h << 16);
}

