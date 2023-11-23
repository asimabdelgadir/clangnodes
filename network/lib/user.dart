class UserEntity {
  bool? status;
  String? message;
  Data? data;
  String? code;
  String? warnings;

  UserEntity({this.status, this.message, this.data, this.code, this.warnings});

  UserEntity.fromJson(Map<String, dynamic> json) {
    status = json['status'] as bool?;
    message = json['message'] as String?;
    data = json['data'] != null ? Data.fromJson(json['data']) : null;
    code = json['code'] as String?;
    warnings = json['warnings'] as String?;
  }

  Map<String, dynamic> toJson() {
    final Map<String, dynamic> data = <String, dynamic>{};
    data['status'] = status;
    data['message'] = message;
    if (this.data != null) {
      data['data'] = this.data!.toJson();
    }
    data['code'] = code;
    data['warnings'] = warnings;
    return data;
  }
}

class Data {
  int? id;
  String? userId;
  String? userEmail;
  String? buyer;
  String? mobile;
  AccessToken? accessToken;
  RefreshToken? refreshToken;
  String? userRole;

  Data(
      {this.id,
      this.userId,
      this.userEmail,
      this.buyer,
      this.mobile,
      this.accessToken,
      this.refreshToken,
      this.userRole});

  Data.fromJson(Map<String, dynamic> json) {
    id = json['id'];
    userId = json['user_id'];
    userEmail = json['user_email'];
    buyer = json['buyer_type'];
    mobile = json['mobile_number'];
    accessToken = json['access_token'] != null
        ? AccessToken.fromJson(json['access_token'])
        : null;
    refreshToken = json['refresh_token'] != null
        ? RefreshToken.fromJson(json['refresh_token'])
        : null;
    userRole = json['user_role'];
  }

  Map<String, dynamic> toJson() {
    final Map<String, dynamic> data = <String, dynamic>{};
    data['id'] = id;
    data['user_id'] = userId;
    data['user_email'] = userEmail;
    data['buyer_type'] = buyer;
    data['mobile_number'] = mobile;

    if (accessToken != null) {
      data['access_token'] = accessToken!.toJson();
    }
    if (refreshToken != null) {
      data['refresh_token'] = refreshToken!.toJson();
    }
    data['user_role'] = userRole;
    return data;
  }
}

class AccessToken {
  String? tokenString;
  String? expireAt;

  AccessToken({this.tokenString, this.expireAt});

  AccessToken.fromJson(Map<String, dynamic> json) {
    tokenString = json['tokenString'];
    expireAt = json['expireAt'];
  }

  Map<String, dynamic> toJson() {
    final Map<String, dynamic> data = <String, dynamic>{};
    data['tokenString'] = tokenString;
    data['expireAt'] = expireAt;
    return data;
  }
}

class RefreshToken {
  String? username;
  String? tokenString;
  String? expireAt;

  RefreshToken({this.username, this.tokenString, this.expireAt});

  RefreshToken.fromJson(Map<String, dynamic> json) {
    username = json['username'];
    tokenString = json['tokenString'];
    expireAt = json['expireAt'];
  }

  Map<String, dynamic> toJson() {
    final Map<String, dynamic> data = <String, dynamic>{};
    data['username'] = username;
    data['tokenString'] = tokenString;
    data['expireAt'] = expireAt;
    return data;
  }
}
