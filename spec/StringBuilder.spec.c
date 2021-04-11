#include "StringBuilder.spec.h"

module(T_StringBuilder, {
    describe("#get_value", {
        it("returns `Hello, World!`", {
            assert_that_charptr(get_value() equals to "Hello, World!");
        });
    });
});

spec_suite({
    T_StringBuilder();
});

spec({
    run_spec_suite("all");
});
