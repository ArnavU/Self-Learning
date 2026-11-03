function createResult(data, error) {
    if(data)
        return successResult(data);
    return errorResult(error);
}

function successResult(data) {
    return { status: 'success', data };
}

function errorResult(error) {
    return { status: 'error', error };
}

module.exports = {createResult, successResult, errorResult};