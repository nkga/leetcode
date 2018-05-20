# leetcode

Solutions to LeetCode problems in C++. Explanations and test cases are included
for most solutions.

 This requires Visual Studio Community
 to build and test since I make use of
 the MSVC unit testing framework. You
 can access it from within the editor
 via `Test -> Windows -> Test Explorer`
 in the menubar.

 Easiest way to test the whole solution
 is by hitting `Ctrl+R, Ctrl+A` by default.
 
Most of these solutions are faster than 90% of submissions
as of writing, and many are faster than 99%. The biggest
performance trick you can do isn't actually anything algorithm
related. Just include:

```cpp
static const auto __ = []() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	return 0;
}();
```

at the top of every single submission. This will typically
cut your execution time in half for each test performed.
