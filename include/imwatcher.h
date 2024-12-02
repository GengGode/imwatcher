#ifndef IMWATCHER_H
#define IMWATCHER_H

    #ifdef __WIN32 
        #ifdef IMWATCHER_EXPORTS
            #define IMWATCHER_API __declspec(dllexport)
        #else
            #define IMWATCHER_API __declspec(dllimport)
        #endif
    #elif __GNUC__ >= 4
        #define IMWATCHER_API __attribute__ ((visibility("default")))
    #else
        #define IMWATCHER_API
    #endif

    #ifdef __cplusplus
        extern "C" {
    #endif

    struct im_watcher;
    typedef struct im_watcher im_watcher_t;
    typedef struct im_watcher* im_watcher_ptr;

    IMWATCHER_API void global_config_dir(const char* dir);
    IMWATCHER_API void global_watcher_register();
    IMWATCHER_API im_watcher_ptr create_watcher();
    IMWATCHER_API void destroy_watcher(im_watcher_ptr watcher);

    struct im_watcher_impl;
    typedef struct im_watcher_impl im_watcher_impl_t;
    typedef struct im_watcher_impl* im_watcher_impl_ptr;
    struct im_watcher
    {
        im_watcher_impl_ptr impl;
        void (*destory)(im_watcher_ptr);

        /// @brief Begin watching an thread
        void (*begin_thread)(im_watcher_ptr, int thread_id);
        void (*end_thread)(im_watcher_ptr, int thread_id);

        /// @brief Begin watching an frame.
        void (*begin_frame)(im_watcher_ptr, const char* name);
        void (*end_frame)(im_watcher_ptr, const char* name);
        
        /// @brief Begin watching an event.
        void (*begin_event)(im_watcher_ptr, const char* name);
        void (*end_event)(im_watcher_ptr, const char* name);
    };

    #ifdef __cplusplus
        }
    #endif

#endif // IMWATCHER_H