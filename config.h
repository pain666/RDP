#ifndef FREERDP_CONFIG_H
#define FREERDP_CONFIG_H

/* Include files */
#define HAVE_FCNTL_H
#if defined(__APPLE__) && !defined(__IOS__)
#define HAVE_UNISTD_H 0
#else
/* #undef HAVE_UNISTD_H */
#endif
#define HAVE_INTTYPES_H
/* #undef HAVE_SYS_MODEM_H */
/* #undef HAVE_SYS_FILIO_H */
/* #undef HAVE_SYS_SELECT_H */
/* #undef HAVE_SYS_SOCKIO_H */
/* #undef HAVE_SYS_STRTIO_H */
/* #undef HAVE_SYS_EVENTFD_H */
/* #undef HAVE_SYS_TIMERFD_H */
/* #undef HAVE_TM_GMTOFF */
/* #undef HAVE_AIO_H */
/* #undef HAVE_POLL_H */
/* #undef HAVE_SYSLOG_H */
/* #undef HAVE_JOURNALD_H */
/* #undef HAVE_PTHREAD_MUTEX_TIMEDLOCK */
/* #undef HAVE_VALGRIND_MEMCHECK_H */
/* #undef HAVE_EXECINFO_H */

/* Features */
/* #undef HAVE_ALIGNED_REQUIRED */

/* Options */
/* #undef WITH_PROFILER */
/* #undef WITH_GPROF */
#define WITH_SSE2
/* #undef WITH_NEON */
/* #undef WITH_IPP */
#define WITH_NATIVE_SSPI
/* #undef WITH_JPEG */
/* #undef WITH_WIN8 */
/* #undef WITH_ICU */
/* #undef WITH_RDPSND_DSOUND */
/* #undef WITH_EVENTFD_READ_WRITE */
/* #undef HAVE_MATH_C99_LONG_DOUBLE */

/* #undef WITH_GSTREAMER_1_0 */
/* #undef WITH_GSTREAMER_0_10 */
#define WITH_WINMM
/* #undef WITH_MACAUDIO */
/* #undef WITH_OSS */
/* #undef WITH_ALSA */
/* #undef WITH_PULSE */
/* #undef WITH_IOSAUDIO */
/* #undef WITH_OPENSLES */
/* #undef WITH_GSM */
/* #undef WITH_LAME */
/* #undef WITH_FAAD2 */
/* #undef WITH_FAAC */
#define WITH_GFX_H264
/* #undef WITH_OPENH264 */
/* #undef WITH_FFMPEG */
/* #undef WITH_DSP_EXPERIMENTAL */
/* #undef WITH_DSP_FFMPEG */
/* #undef WITH_X264 */
#define WITH_MEDIA_FOUNDATION

/* #undef WITH_VAAPI */

/* Plugins */
#define BUILTIN_CHANNELS
/* #undef WITH_RDPDR */

/* Channels */
/* #undef CHANNEL_AUDIN */
/* #undef CHANNEL_AUDIN_CLIENT */
/* #undef CHANNEL_AUDIN_SERVER */
/* #undef CHANNEL_CLIPRDR */
/* #undef CHANNEL_CLIPRDR_CLIENT */
/* #undef CHANNEL_CLIPRDR_SERVER */
/* #undef CHANNEL_DISP */
/* #undef CHANNEL_DISP_CLIENT */
/* #undef CHANNEL_DISP_SERVER */
/* #undef CHANNEL_DRDYNVC */
/* #undef CHANNEL_DRDYNVC_CLIENT */
/* #undef CHANNEL_DRDYNVC_SERVER */
/* #undef CHANNEL_DRIVE */
/* #undef CHANNEL_DRIVE_CLIENT */
/* #undef CHANNEL_DRIVE_SERVER */
/* #undef CHANNEL_ECHO */
/* #undef CHANNEL_ECHO_CLIENT */
/* #undef CHANNEL_ECHO_SERVER */
/* #undef CHANNEL_ENCOMSP */
/* #undef CHANNEL_ENCOMSP_CLIENT */
/* #undef CHANNEL_ENCOMSP_SERVER */
/* #undef CHANNEL_PARALLEL */
/* #undef CHANNEL_PARALLEL_CLIENT */
/* #undef CHANNEL_PARALLEL_SERVER */
/* #undef CHANNEL_PRINTER */
/* #undef CHANNEL_PRINTER_CLIENT */
/* #undef CHANNEL_PRINTER_SERVER */
/* #undef CHANNEL_RAIL */
/* #undef CHANNEL_RAIL_CLIENT */
/* #undef CHANNEL_RAIL_SERVER */
/* #undef CHANNEL_RDPDR */
/* #undef CHANNEL_RDPDR_CLIENT */
/* #undef CHANNEL_RDPDR_SERVER */
/* #undef CHANNEL_RDPEI */
/* #undef CHANNEL_RDPEI_CLIENT */
/* #undef CHANNEL_RDPEI_SERVER */
/* #undef CHANNEL_RDPGFX */
/* #undef CHANNEL_RDPGFX_CLIENT */
/* #undef CHANNEL_RDPGFX_SERVER */
/* #undef CHANNEL_RDPSND */
/* #undef CHANNEL_RDPSND_CLIENT */
/* #undef CHANNEL_RDPSND_SERVER */
/* #undef CHANNEL_REMDESK */
/* #undef CHANNEL_REMDESK_CLIENT */
/* #undef CHANNEL_REMDESK_SERVER */
/* #undef CHANNEL_SERIAL */
/* #undef CHANNEL_SERIAL_CLIENT */
/* #undef CHANNEL_SERIAL_SERVER */
/* #undef CHANNEL_SMARTCARD */
/* #undef CHANNEL_SMARTCARD_CLIENT */
/* #undef CHANNEL_SMARTCARD_SERVER */
/* #undef CHANNEL_SSHAGENT */
/* #undef CHANNEL_SSHAGENT_CLIENT */
/* #undef CHANNEL_SSHAGENT_SERVER */
/* #undef CHANNEL_TSMF */
/* #undef CHANNEL_TSMF_CLIENT */
/* #undef CHANNEL_TSMF_SERVER */
/* #undef CHANNEL_URBDRC */
/* #undef CHANNEL_URBDRC_CLIENT */
/* #undef CHANNEL_URBDRC_SERVER */

/* Debug */
/* #undef WITH_DEBUG_CERTIFICATE */
/* #undef WITH_DEBUG_CAPABILITIES */
/* #undef WITH_DEBUG_CHANNELS */
/* #undef WITH_DEBUG_CLIPRDR */
/* #undef WITH_DEBUG_DVC */
/* #undef WITH_DEBUG_TSMF */
/* #undef WITH_DEBUG_KBD */
/* #undef WITH_DEBUG_LICENSE */
/* #undef WITH_DEBUG_NEGO */
/* #undef WITH_DEBUG_NLA */
/* #undef WITH_DEBUG_NTLM */
/* #undef WITH_DEBUG_TSG */
/* #undef WITH_DEBUG_RAIL */
/* #undef WITH_DEBUG_RDP */
/* #undef WITH_DEBUG_REDIR */
/* #undef WITH_DEBUG_RDPDR */
/* #undef WITH_DEBUG_RFX */
/* #undef WITH_DEBUG_SCARD */
/* #undef WITH_DEBUG_SND */
/* #undef WITH_DEBUG_SVC */
/* #undef WITH_DEBUG_RDPEI */
/* #undef WITH_DEBUG_TIMEZONE */
/* #undef WITH_DEBUG_THREADS */
/* #undef WITH_DEBUG_MUTEX */
/* #undef WITH_DEBUG_TRANSPORT */
/* #undef WITH_DEBUG_WND */
/* #undef WITH_DEBUG_X11 */
/* #undef WITH_DEBUG_X11_CLIPRDR */
/* #undef WITH_DEBUG_X11_LOCAL_MOVESIZE */
/* #undef WITH_DEBUG_XV */
/* #undef WITH_DEBUG_RINGBUFFER */
#endif /* FREERDP_CONFIG_H */
