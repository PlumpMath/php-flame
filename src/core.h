#pragma once

class core {
public:
	// io_servcie 需要在 module 的 startup 流程中启动 shutdown 流程中销毁
	// 内部任务队列引用了 PHP 对象，这些对象会在 shutdown 之前被 PHP 主动销毁
	static inline boost::asio::io_service& io() {
		return *io_;
	}
	static void init(php::extension_entry& extension);
	static php::value error_to_exception(const boost::system::error_code& err);
private:
	static boost::asio::io_service* io_;
	static bool module_startup (php::extension_entry& extension);
	static bool module_shutdown(php::extension_entry& extension);
	static php::value go(php::parameters& params);
	static php::value run(php::parameters& params);
	static php::value sleep(php::parameters& params);
	static php::value _fork(php::parameters& params);
};
