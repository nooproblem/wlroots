version_array = meson.project_version().split('.')
version_data = configuration_data()
version_data.set_quoted('WLR_VERSION_STR',   meson.project_version())
version_data.set('WLR_VERSION_MAJOR',        version_array[0])
version_data.set('WLR_VERSION_MINOR',        version_array[1])
version_data.set('WLR_VERSION_MICRO',        version_array[2])
version_data.set('WLR_VERSION_API_CURRENT',  so_version[0])
version_data.set('WLR_VERSION_API_REVISION', so_version[1])
version_data.set('WLR_VERSION_API_AGE',      so_version[2])

install_headers(
	configure_file(input: 'config.h.in', output: 'config.h',configuration: conf_data),
	configure_file(input: 'version.h.in', output: 'version.h', configuration: version_data),
	'backend.h',
	'xcursor.h',
	subdir: 'wlr'
)
if conf_data.get('WLR_HAS_XWAYLAND', 0) == 1
	install_headers('xwayland.h', subdir: 'wlr')
endif

subdir('backend')
subdir('interfaces')
subdir('render')
subdir('types')
subdir('util')
