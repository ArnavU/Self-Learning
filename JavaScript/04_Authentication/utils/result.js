// createResult
function createResult(data, err) {
	if (data) {
		return createSuccessResult(data);
	} else {
		return createErrorResult(err);
	}
}

// createSuccessResult
function createSuccessResult(data) {
	return { status: "success", data };
}

// createErrorResult
function createErrorResult(err) {
	return { status: "error", err };
}

module.exports = { createResult, createSuccessResult, createErrorResult };
